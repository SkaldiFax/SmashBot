#ifndef FAX_GAMESERVICE_H
#define FAX_GAMESERVICE_H

#include <SFML/Graphics.hpp>
#include "Hitbox.h"
#include "RenderService.h"
#include <list>

namespace FAX {
	class GameService {
	private:
		RenderService* m_renderService;
		std::list<Hitbox> m_hitboxes;

	public:
		GameService();
		GameService(RenderService& renderService);

		void render();
	};
}

#endif
