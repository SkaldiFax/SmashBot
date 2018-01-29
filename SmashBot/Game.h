#ifndef FAX_GAME_H
#define FAX_GAME_H

#include <SFML/Graphics.hpp>
#include "Hitbox.h"
#include "RenderService.h"
#include "GameService.h"

namespace FAX {
	const Vector2 windowSize(1080.0f, 720.0f);

	class Game {
	private:
		RenderService m_renderService;
		GameService m_gameService;

	public:
		Game();

		void initialize();
		void render();
	};
}

#endif
