#include "systems\HUDSystem.h"

HUDSystem::HUDSystem(entityx::EntityManager& entities, 
					sf::RenderWindow &window) :
	m_entities(entities),
	m_window(window)
{
	readFont();
	m_text.setFont(m_font);
	m_text.setColor(sf::Color::Black);
}

void HUDSystem::configure(entityx::EventManager &eventManager)
{
	eventManager.subscribe<EvReportNode>(*this);
}

void HUDSystem::receive(const EvReportNode& e)
{
	m_index = e.m_index;
}

void HUDSystem::update(entityx::EntityManager& entities,
	entityx::EventManager& events,
	double dt)
{

	m_time += dt / 1000.f; // to get it to seconds

	m_text.setString("Time taken : " + std::to_string(m_time)
		+ "\nCurrent Node:" + std::to_string(m_index));
	m_window.draw(m_text);
}
void HUDSystem::readFont()
{
	if (!m_font.loadFromFile("./resources/fonts/akashi.ttf"))
	{
		std::cout << "The font is not loaded!" << std::endl;
	}
}