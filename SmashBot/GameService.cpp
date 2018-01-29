#include "stdafx.h"
#include "GameService.h"

namespace FAX {
	GameService::GameService() {}
	GameService::GameService(RenderService& renderService) {
		m_renderService = &renderService;

		// Test hitboxes
		m_hitboxes = std::list<Hitbox>();
		m_hitboxes.push_back(Hitbox(
			Vector2(0.0f, 0.0f),
			Vector2(100.0f, 100.0f)
		));
		m_hitboxes.push_back(Hitbox(
			Vector2(50.0f, 0.0f),
			Vector2(100.0f, 50.0f)
		));
		m_hitboxes.push_back(Hitbox(
			Vector2(200.0f, 200.0f),
			Vector2(50.0f, 50.0f)
		));
	}

	void GameService::render() {
		for (auto iterator = m_hitboxes.begin(); iterator != m_hitboxes.end(); ++iterator) {
			iterator->render(*m_renderService);
		}
	}
}
