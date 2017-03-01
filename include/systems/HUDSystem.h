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
	HUDSystem(sf::RenderWindow &window); // constructor
	void HUDSystem::configure(entityx::EventManager &eventManager);
	void receive(const EvReportNode& e); // receiving method
	void update(entityx::EntityManager& entities, // for updating hud display
		entityx::EventManager& events,
		double dt);
	void readFont(); // to read font
private:
	//std::unique_ptr<TankAi> m_tankAi;
	float m_time; // the time
	float m_timeTaken; // the time taken to complete lap

	int m_index; // current index
	int m_prevIndex; // prev index

	int laps; // number of total laps

	sf::Font m_font; // to write text
	sf::Text m_text; // to display text to screen
	sf::RenderWindow &m_window;
};