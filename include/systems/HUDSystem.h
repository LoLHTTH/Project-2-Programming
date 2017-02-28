#pragma once
#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"
#include "EntityCreator.h"
#include "components/Ai.h"

class HUDSystem
	: public entityx::System<HUDSystem>
	, public entityx::Receiver<HUDSystem>
{
public:
	HUDSystem(entityx::EntityManager& entities, sf::RenderWindow &window);
	void HUDSystem::configure(entityx::EventManager &eventManager);
	void receive(const EvReportNode& e);
	void update(entityx::EntityManager& entities,
		entityx::EventManager& events,
		double dt);
	void readFont();
private:
	std::unique_ptr<TankAi> m_tankAi;
	float m_time;
	int m_index;
	sf::Font m_font;
	sf::Text m_text;
	sf::RenderWindow &m_window;
	entityx::EntityManager& m_entities;
	sf::Clock m_clock;
};