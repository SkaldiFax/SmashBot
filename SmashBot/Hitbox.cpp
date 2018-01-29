#include "stdafx.h"
#include "Hitbox.h"

namespace FAX {
	Hitbox::Hitbox(Vector2 origin, Vector2 size) {
		m_origin = origin;
		m_size = size;
	}

	void Hitbox::render(RenderService& renderService) {
		renderService.renderDebugBox(m_origin, m_size, sf::Color::Red);
	}
}