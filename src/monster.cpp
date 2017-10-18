#include "Monster.h"
#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>

Monster::Monster(Race race)
{
	std::cout << "Enter the orc's stats and then the troll stats please. \n";

	std::cout << "HP: ";
	std::cin >> this->Health;

	std::cout << "Attack : ";
	std::cin >> this->AttackPower;

	std::cout << "Defense : ";
	std::cin >> this->DefensivePower;
		
	std::cout << "Speed : ";
	std::cin >> this->Speed;
}

Monster::~Monster()
{
}

void Monster::attack(Monster& defender, sf::RenderWindow& window, sf::Text& damage_text)
{
	std::string damage_string;
	int damage = this->AttackPower - defender.DefensivePower;
	if (damage <= 0)
	{
		damage = 1;
	}
	defender.Health = defender.Health - damage;

	damage_string = std::to_string(damage);

	damage_text.setString(damage_string);
	damage_text.setColor(sf::Color::Red);
	damage_text.setPosition(350, 10);
	damage_text.setCharacterSize(30);
}
