#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Hitbox.h";

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SmashBot");

	FAX::Hitbox hitbox(
		FAX::Vector2(50.f, 100.f),
		FAX::Vector2(25.f, 25.f)
	);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		hitbox.render(window);
		window.display();
	}
}