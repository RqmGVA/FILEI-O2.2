#include <SFML/Graphics.hpp>
#include <iostream>
#include "monster.h"

#define LOWEST_MONSTER_HEALTH 0
void showScreen(sf::RenderWindow &window, sf::Sprite troll, sf::Sprite orc, sf::Text damage_text)
{
	window.clear();
	window.draw(troll);
	window.draw(orc);
	window.draw(damage_text);
	window.display();
}

int main()
{
	//Monster initialisation
	Monster orc = Monster(ORC);
	Monster troll = Monster(TROLL);

	//Window setup
	sf::RenderWindow window(sf::VideoMode(800, 600), "Monster's battle simulator");
	window.setFramerateLimit(60);

	//Troll
	sf::Texture troll_texture;
	sf::Sprite troll_sprite;
	troll_texture.loadFromFile("data/troll.png");
	troll_sprite.setTexture(troll_texture);
	troll_sprite.setScale(3., 3.);
	troll_sprite.setPosition(475, 75);
	//Orc
	sf::Texture orc_texture;
	sf::Sprite orc_sprite;
	orc_texture.loadFromFile("data/orc.png");
	orc_sprite.setTexture(orc_texture);
	orc_sprite.setScale(0.5, 0.5);
	orc_sprite.setPosition(0, 100);
	//Damage
	sf::Font damage_font;
	sf::Text damage_text;
	damage_font.loadFromFile("data/BERNHC.ttf");
	damage_text.setFont(damage_font);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			showScreen(window,troll_sprite, orc_sprite, damage_text);

			int turn = 0;

			bool monster1turn=true;
			orc.Speed > troll.Speed ? monster1turn = true : monster1turn = false;

			while ((orc.Health >  LOWEST_MONSTER_HEALTH) && (troll.Health >  LOWEST_MONSTER_HEALTH))
			{
				//Timer
				sf::Time elapsed;
				sf::Clock clock;

				while (elapsed.asSeconds() != 1.0f)
				{
					elapsed = clock.getElapsedTime();
				}

				troll_sprite.setPosition(475, 75);
				orc_sprite.setPosition(0, 100);

				showScreen(window, troll_sprite, orc_sprite, damage_text);
				//Timer
				while (elapsed.asSeconds() != 2.0f)
				{
					elapsed = clock.getElapsedTime();
				}
				//Attack
				if (monster1turn)
				{
					orc.attack(troll,window, damage_text);
					orc_sprite.setPosition(400, 100);
					troll_sprite.setPosition(475, 75);
					showScreen(window, troll_sprite, orc_sprite, damage_text);
				}
				else
				{
					troll.attack(orc, window, damage_text);
					orc_sprite.setPosition(0, 100);
					troll_sprite.setPosition(100, 75);
					showScreen(window, troll_sprite, orc_sprite, damage_text);
				}
			
				monster1turn = !monster1turn;
				turn++;

				if (troll.Health<= LOWEST_MONSTER_HEALTH || orc.Health <= LOWEST_MONSTER_HEALTH)
				{
					std::cout << "Monster ";
					troll.Health <= LOWEST_MONSTER_HEALTH ? std::cout << "1" : std::cout << "2";
					std::cout << " won! The battle took " << turn << " turn(s) !";
				}
			}
		}
	}
	
	system("pause");
	return 0;
}