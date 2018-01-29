#ifndef FAX_HITBOX_H
#define FAX_HITBOX_H

#include "Vector2.h"
#include "RenderService.h"
#include <SFML/Graphics.hpp>

namespace FAX {
	class Hitbox {
	private:
		Vector2 m_origin;
		Vector2 m_size;

	public:
		Hitbox(Vector2 origin, Vector2 size);

		void render(RenderService& renderService);
	};
}


#endif