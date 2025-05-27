#pragma once
#include <iostream>
#include <string>

#include "Behavior.h"
#include "Position.h"
#include "World.h"

struct AncestorHistoryItem
{
	int births;
	int deaths;
};

class Organism
{
	/// Unikalny identyfikator organizmu w świecie.
	int id;

	/// Siła organizmu. Zwiększa się o <code>1</code> co turę.
	int power;

	/// Priorytet decydujący o kolejności wykonania ruchu w ramach jednej tury.
	int initiative;

	/// Czas życia (w turach).
	int liveLength;

	/// Minimalna ilość siły (<code>power</code>) wymaganej, aby organizm mógł się rozmnożyć.
	int powerToReproduce;

	/// Pozycja organizmu na planszy.
	Position position;

	/// Znak reprezentujący organizm na planszy.
	char sign;

	/// Historia przodków organizmu.
	std::vector<AncestorHistoryItem> ancestorsHistory;

public:
	// Konstruktor "explicit"
	Organism(char sign, int id, Position position, int power, int initiative, int liveLength, int powerToReproduce);

	// Konstruktor kopiujący
	Organism(const Organism& other);

	// Konstruktor przenoszący
	Organism(Organism&& other) noexcept;

	// Destruktor
	virtual ~Organism() = default;

	int getPower() const;
	void setPower(int power);

	Position getPosition() const;
	void setPosition(Position position);

	char getSign() const;
	void setSign(char spec);

	int getId() const;

	std::vector<AncestorHistoryItem>& getAncestorsHistory();
	void addAncestorHistoryItem(int births, int deaths);

	virtual void move(int dx, int dy);
	virtual void behave(World& world);
	std::string toString() const;

	// Kopiujący operator przypisania
	Organism& operator=(const Organism& other);

	// Przenoszący operator przypisania
	Organism& operator=(Organism&& other) noexcept;
};