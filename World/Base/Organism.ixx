module;

#include <vector>

export module World.Base.Organism;

import World.Models.Position;
import World.Models.AncestorHistoryItem;
import World.Base.Interfaces.IOrganism;

export class Organism : public IOrganism
{
    /// Unikalny identyfikator organizmu w świecie.
    int id;

    /// Siła organizmu. Zwiększa się o <code>1</code> co turę.<br/> <b>Domyślnie</b> <code>0</code>.
    int power;

    /// Priorytet decydujący o kolejności wykonania ruchu w ramach jednej tury. Niższa liczba oznacza wyższy priorytet.<br/> <b>Domyślnie</b> <code>0</code>.
    int initiative;

    /// Czas życia (w turach). Jeżeli wynosi <code>-1</code> to organizm jest nieśmiertelny.<br/> <b>Domyślnie</b> <code>-1</code>.
    int liveLength;

    /// Minimalna ilość siły (<code>power</code>) wymaganej, aby organizm mógł się rozmnożyć.</br> <b>Domyślnie</b> <code>0</code>.
    int powerToReproduce;

    /// Pozycja organizmu na planszy.
    Position position{};

    /// Znak reprezentujący organizm na planszy.</br> <b>Domyślnie</b> <code>'_'</code>.
    char sign;

    /// Historia przodków organizmu.
    std::vector<AncestorHistoryItem> ancestorsHistory{};

public:
    // Konstruktor "explicit"
    explicit Organism(const int id)
        :
        id(id),
        power(0),
        initiative(0),
        liveLength(-1),
        powerToReproduce(0),
        sign('_')
    {

    }

    // Konstruktor kopiujący
    Organism(const Organism& other) = default;

    // Konstruktor przenoszący
    Organism(Organism&& other) noexcept = default;

    virtual void init() = 0;

    [[nodiscard]] int getPower() const override
    {
        return this->power;
    }

    void setPower(const int power) override
    {
        this->power = power;
    }

    [[nodiscard]] int getInitiative() const override
    {
        return this->initiative;
    }

    void setInitiative(const int initiative) override
    {
        this->initiative = initiative;
    }

    [[nodiscard]] int getLiveLength() const override
    {
        return this->liveLength;
    }

    void setLiveLength(const int liveLength) override
    {
        this->liveLength = liveLength;
    }

    [[nodiscard]] int getPowerToReproduce() const override
    {
        return this->powerToReproduce;
    }

    void setPowerToReproduce(const int powerToReproduce) override
    {
        this->powerToReproduce = powerToReproduce;
    }

    [[nodiscard]] Position getPosition() const override
    {
        return this->position;
    }

    void setPosition(const Position position) override
    {
        this->position = position;
    }

    [[nodiscard]] char getSign() const override
    {
        return this->sign;
    }

    void setSign(const char spec) override
    {
        this->sign = spec;
    }

    [[nodiscard]] int getId() const override
    {
        return this->id;
    }

    std::vector<AncestorHistoryItem>& getAncestorsHistory()
    {
        return this->ancestorsHistory;
    }

    void addAncestorHistoryItem(const int births, const int deaths)
    {
        const AncestorHistoryItem item{ births, deaths };
        this->ancestorsHistory.push_back(item);
    }

    [[nodiscard]] std::string toString() const
    {
        return "{ species: " + std::string(1, this->getSign()) +
        ", power: " + std::to_string(getPower()) +
        ", position: " + getPosition().toString() + "}";
    }

    // Kopiujący operator przypisania
    Organism& operator=(const Organism& other)
    {
        if (this != &other) {
            power = other.power;
            position = other.position;
            sign = other.sign;
            ancestorsHistory = other.ancestorsHistory;
        }

        return *this;
    }

    // Przenoszący operator przypisania
    Organism& operator=(Organism&& other) noexcept
    {
        if (this != &other) {
            power = other.power;
            position = other.position;
            sign = other.sign;
            ancestorsHistory = std::move(other.ancestorsHistory);
        }

        return *this;
    }
};
