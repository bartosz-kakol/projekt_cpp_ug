#include "Organism.h"

// Konstruktor "explicit"
Organism::Organism(
	const int power, const int initiative, const int liveLength, const int powerToReproduce, const Position position,
	const char sign
)
    :
	power(power),
	initiative(initiative),
	liveLength(liveLength),
	powerToReproduce(powerToReproduce),
	position(position),
	sign(sign)
{

}

// Konstruktor kopiujący
Organism::Organism(const Organism& other) = default;

// Konstruktor przenoszący
Organism::Organism(Organism&& other) noexcept = default;


int Organism::getPower() const
{
	return this->power;
}

void Organism::setPower(const int power)
{
	this->power = power;
}

Position Organism::getPosition() const
{
	return this->position;
}

void Organism::setPosition(const Position position)
{
	this->position = position;
}

std::string Organism::toString() const
{
	return "{ species: " + std::string(1, this->getSign()) +
		", power: " + std::to_string(getPower()) +
		", position: " + getPosition().toString() + "}";
}

void Organism::move(const int dx, const int dy)
{
	position.move(dx, dy);
}

char Organism::getSign() const
{
	return this->sign;
}

void Organism::setSign(const char spec)
{
	this->sign = spec;
}

std::vector<AncestorHistoryItem>& Organism::getAncestorsHistory()
{
	return this->ancestorsHistory;
}

void Organism::addAncestorHistoryItem(const int births, const int deaths)
{
    const AncestorHistoryItem item{ births, deaths };
    this->ancestorsHistory.push_back(item);
}

void Organism::behave(World& world)
{
	std::cout << "Domyślny behave()!!!" << std::endl;
}

// Kopiujący operator przypisania
Organism& Organism::operator=(const Organism& other)
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
Organism& Organism::operator=(Organism&& other) noexcept
{
	if (this != &other) {
		power = other.power;
		position = other.position;
		sign = other.sign;
		ancestorsHistory = std::move(other.ancestorsHistory);
	}

	return *this;
}
