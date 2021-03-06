#include "stdafx.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>

class RandomGenerator {
public:
	static float uniformUnitReal(float lower, float upper) {
		static std::mt19937 generator(time(nullptr));
		const std::uniform_real_distribution<float> uniformRealDistribution(lower, upper);
		return uniformRealDistribution(generator);
	}
};

class PhysicsCircle {
public:
	float px, py, vx, vy, radius;
	sf::CircleShape renderObject;

	PhysicsCircle(float i_px, float i_py, float i_radius) : px(i_px), py(i_py), radius(i_radius) {
		renderObject.setRadius(radius);
		renderObject.setOrigin(radius, radius);
		renderObject.setFillColor(sf::Color::Blue);
		vx = RandomGenerator::uniformUnitReal(-250.0, 250.0);
		vy = RandomGenerator::uniformUnitReal(-250.0, 250.0);
	}

	void update(float interval) {
		px += vx * interval;
		py += vy * interval;
	}

	sf::CircleShape& getRenderObject() {
		renderObject.setPosition(px, py);
		return renderObject;
	}
};

int main()
{
	std::mt19937 randomGenerator(time(nullptr));
	std::uniform_real_distribution<float> randomUniformDistribution(0.0f, 1.0f);
	randomUniformDistribution(randomGenerator);

	sf::RenderWindow window(sf::VideoMode(800, 600), "Smashbot 1000", sf::Style::None);
	
	std::vector<PhysicsCircle> physicsObjects;
	physicsObjects.push_back(
		PhysicsCircle(200.0f, 200.0f, 50.0f)
	);
	physicsObjects.push_back(
		PhysicsCircle(400.0f, 200.0f, 25.0f)
	);
	physicsObjects.push_back(
		PhysicsCircle(300.0f, 300.0f, 70.0f)
	);

	sf::Clock updateClock;

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.close();
				}
			}
		}

		float updateInterval = updateClock.getElapsedTime().asSeconds();
		updateClock.restart();

		for (auto& physicsObject : physicsObjects) {
			physicsObject.update(updateInterval);
		}

		// lol collision checks
		for (auto ita = physicsObjects.begin(); ita != physicsObjects.end(); ++ita) {
			for (auto itb = ita; itb != physicsObjects.end(); ++itb) {
				if (std::pow(ita->px - itb->px, 2.0f) + std::pow(ita->py - itb->py, 2.0f) <= std::pow(ita->radius + itb->radius, 2.0f)) {
					// BOING
					ita->vx *= -1.0f;
					ita->vy *= -1.0f;
					itb->vx *= -1.0f;
					itb->vy *= -1.0f;
					// totally realistic
				}
			}
		}

		for (auto it = physicsObjects.begin(); it != physicsObjects.end(); ++it) {
			if (it->px <= it->radius || it->py <= it->radius || it->px >= 800.0f - it->radius || it->py >= 600.0f - it->radius) {
				// BOING
				it->vx *= -1.0f;
				it->vy *= -1.0f;
				// totally realistic
			}
		}

		window.clear(sf::Color::Black);
		for (auto& physicsObject : physicsObjects) {
			window.draw(physicsObject.getRenderObject());
		}
		window.display();
	}

	return 0;
}