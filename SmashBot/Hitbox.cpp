#include "stdafx.h"
#include "Hitbox.h"

namespace FAX {
	Hitbox::Hitbox(Vector2 origin, Vector2 size) {
		m_origin = origin;
		m_size = size;
	}

	void Hitbox::render(sf::RenderTarget& renderTarget) {
		Vector2 pos = m_origin - (0.5f * m_size);
		sf::RectangleShape displayObject;
		displayObject.setSize(sf::Vector2f(m_origin.x, m_origin.y));
		displayObject.setPosition(sf::Vector2f(pos.x, pos.y));
		displayObject.setFillColor(sf::Color::Transparent);
		displayObject.setOutlineThickness(1);
		displayObject.setOutlineColor(sf::Color::Red);
		renderTarget.draw(displayObject);
	}
}