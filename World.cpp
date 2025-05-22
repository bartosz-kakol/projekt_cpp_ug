#include "World.h"
#include "Organism.h"
#include <fstream>
#include <random>

std::vector<Organism*> World::getOrganismsFromPosition(const int x, const int y) const
{
	std::vector<Organism*> result;

	for (auto& org : organisms)
	{
		if (org->getPosition().getX() == x && org->getPosition().getY() == y)
		{
			result.push_back(org.get());
		}
	}

	return result;
}

bool World::isPositionOnWorld(const int x, const int y) const
{
	return (x >= 0 && y >= 0 && x < getWidth() && y < getHeight());
}

bool World::isPositionFree(const Position position) const
{
	return this->getOrganismsFromPosition(position.getX(), position.getY()).empty();
}

std::vector<Position> World::getVectorOfFreePositionsAround(const Position position) const
{
	const int pos_x = position.getX();
	const int pos_y = position.getY();

	std::vector<Position> result;

	for (int x = -1; x < 2; ++x)
	{
		for (int y = -1; y < 2; ++y)
		{
			if (
				(x != 0 || y != 0) &&
				isPositionOnWorld(pos_x + x, pos_y + y)
			) {
				result.emplace_back(pos_x + x, pos_y + y);
			}
		}
	}

	const auto iter = remove_if(
		result.begin(),
		result.end(),
		[this](const Position pos)
		{
			return !isPositionFree(pos);
		}
	);
	result.erase(iter, result.end());

	return result;
}

World::World(const int width, const int height)
	: width(width), height(height) {}

int World::getWidth() const
{
	return this->width;
}

void World::setWidth(const int width)
{
	this->width = width;
}

int World::getHeight() const
{
	return this->height;
}

void World::setHeight(const int height)
{
	this->height = height;
}

int World::getTurn() const
{
	return this->turn;
}

void World::addOrganism(std::unique_ptr<Organism> organism)
{
	this->organisms.push_back(std::move(organism));
}

void World::makeTurn(const unsigned randomSeed)
{
	std::cout << "TURA ------------------------" << std::endl;

	for (const auto& org : organisms) {
		std::cout << "\tOrganizm " << org->getSign() << ":" << std::endl;

		org->behave(*this);

		std::cout << std::endl;

		// // Inicjalizacja generatora liczb losowych
		// std::mt19937 rng(randomSeed);
		// // Sprawdzenie wolnych pozycji dookoła organizmu
		// std::vector<Position> newPositions = getVectorOfFreePositionsAround(org->getPosition());
		// const int numberOfNewPositions = static_cast<int>(newPositions.size());
		//
		// if (numberOfNewPositions > 0) {
		// 	// Wygenerowanie liczby losowej do zdobycia losowej wolnej pozycji
		// 	std::uniform_int_distribution<> dist(0, numberOfNewPositions - 1);
		// 	const int randomIndex = dist(rng);
		//
		// 	org->setPosition(newPositions[randomIndex]);
		// }
	}

	turn++;
	std::cout << "------------------------ TURA" << std::endl;
}

void World::makeTurn()
{
	makeTurn(static_cast<unsigned>(std::time(nullptr)));
}

void World::writeWorld(const std::string& fileName)
{
	// fstream my_file;
	// my_file.open(fileName, ios::out | ios::binary);
	// if (my_file.is_open()) {
	// 	my_file.write((char*)&this->width, sizeof(int));
	// 	my_file.write((char*)&this->height, sizeof(int));
	// 	my_file.write((char*)&this->turn, sizeof(int));
	// 	int orgs_size = this->organisms.size();
	// 	my_file.write((char*)&orgs_size, sizeof(int));
	// 	for (int i = 0; i < orgs_size; i++) {
	// 		int data;
	// 		data = this->organisms[i].getPower();
	// 		my_file.write((char*)&data, sizeof(int));
	// 		data = this->organisms[i].getPosition().getX();
	// 		my_file.write((char*)&data, sizeof(int));
	// 		data = this->organisms[i].getPosition().getY();
	// 		my_file.write((char*)&data, sizeof(int));
	// 		string s_data = this->organisms[i].getSign();
	// 		int s_size = s_data.size();
	// 		my_file.write((char*)&s_size, sizeof(int));
	// 		my_file.write(s_data.data(), s_data.size());
	// 	}
	// 	my_file.close();
	// }
}

void World::readWorld(std::string fileName)
{
	// fstream my_file;
	// my_file.open(fileName, ios::in | ios::binary);
	// if (my_file.is_open()) {
	// 	int result;
	// 	my_file.read((char*)&result, sizeof(int));
	// 	this->width = (int)result;
	// 	my_file.read((char*)&result, sizeof(int));
	// 	this->height = (int)result;
	// 	my_file.read((char*)&result, sizeof(int));
	// 	this->turn = (int)result;
	// 	my_file.read((char*)&result, sizeof(int));
	// 	int orgs_size = (int)result;
	// 	vector<Organism> new_organisms;
	// 	for (int i = 0; i < orgs_size; i++) {
	// 		int power;
	// 		my_file.read((char*)&result, sizeof(int));
	// 		power = (int)result;
	//
	// 		int pos_x;
	// 		my_file.read((char*)&result, sizeof(int));
	// 		pos_x = (int)result;
	// 		int pos_y;
	// 		my_file.read((char*)&result, sizeof(int));
	// 		pos_y = (int)result;
	// 		Position pos{ pos_x, pos_y };
	//
	// 		int s_size;
	// 		my_file.read((char*)&result, sizeof(int));
	// 		s_size = (int)result;
	//
	// 		string species;
	// 		species.resize(s_size);
	// 		my_file.read((char*)&species[0], s_size);
	//
	// 		Organism org(power, pos);
	// 		org.setSpecies(species);
	// 		new_organisms.push_back(org);
	// 	}
	// 	this->organisms = new_organisms;
	// 	my_file.close();
	// }
}

std::string World::toString() const
{
	std::string result = "\nturn: " + std::to_string(getTurn()) + "\n";

	for (int wY = 0; wY < getHeight(); ++wY) {
		for (int wX = 0; wX < getWidth(); ++wX) {
			const auto organisms = getOrganismsFromPosition(wX, wY);

			if (!organisms.empty())
				result += organisms[0]->getSign();
			else
				result += separator;

			result += ' ';
		}

		result += "\n";
	}

	return result;
}

