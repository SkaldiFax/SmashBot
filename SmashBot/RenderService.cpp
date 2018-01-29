#include "stdafx.h"
#include "RenderService.h"

namespace FAX {
	RenderService::RenderService() {}
	RenderService::RenderService(sf::RenderTarget& renderTarget) {
		m_renderTarget = &renderTarget;
	}

	void RenderService::renderDebugBox(Vector2 origin, Vector2 size, sf::Color color) {
		// Convert game units to pixels.
		float gameUnitsToPixelRatio = m_renderTarget->getSize().y / 1000.0f;

		origin *= gameUnitsToPixelRatio;
		size *= gameUnitsToPixelRatio;

		Vector2 renderPosition = origin - (0.5f * size);

		sf::RectangleShape displayObject;
		displayObject.setSize(sf::Vector2f(size.x, size.y));
		displayObject.setPosition(sf::Vector2f(renderPosition.x, renderPosition.y));
		displayObject.setFillColor(sf::Color::Transparent);
		displayObject.setOutlineThickness(1.0f);
		displayObject.setOutlineColor(color);

		m_renderTarget->draw(displayObject);
	}

}
