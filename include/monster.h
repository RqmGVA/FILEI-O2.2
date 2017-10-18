#ifndef MONSTER_H
#define MONSTER_H

#include <SFML\Graphics.hpp>

enum Race
{
	ORC = 1,
	TROLL = 2
};

class Monster
{
public:
	Monster(Race race);
	~Monster();

	void attack(Monster& defender, sf::RenderWindow &window, sf::Text &damage_text);

	Race race;

	double Health;
	double AttackPower;
	double DefensivePower;
	double Speed;
};

#endif