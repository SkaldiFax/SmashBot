#ifndef FAX_RENDERSERVICE_H
#define FAX_RENDERSERVICE_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"

namespace FAX {
	class RenderService {
	private:
		sf::RenderTarget* m_renderTarget;

	public:
		RenderService();
		RenderService(sf::RenderTarget& renderTarget);

		void renderDebugBox(Vector2 origin, Vector2 size, sf::Color color);
	};
}

#endif
