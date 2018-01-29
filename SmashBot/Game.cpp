#include "stdafx.h"
#include "Game.h"

namespace FAX {
	Game::Game() {
		sf::View view(
			sf::Vector2f(0.0f, 0.0f),
			sf::Vector2f(windowSize.x, windowSize.y)
		);
		view.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
		sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SmashBot");
		window.setView(view);

		m_renderService = RenderService(window);
		m_gameService = GameService(m_renderService);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			render();
			window.display();
		}
	}

	void Game::initialize() {
		sf::View view(
			sf::Vector2f(0.0f, 0.0f),
			sf::Vector2f(windowSize.x, windowSize.y)
		);
		view.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
		sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SmashBot");
		window.setView(view);

		m_renderService = RenderService(window);
		// Test hitboxes


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			render();
			window.display();
		}
	}

	void Game::render() {
		m_gameService.render();
	}
}
