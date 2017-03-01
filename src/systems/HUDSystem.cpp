#include "systems\HUDSystem.h"

HUDSystem::HUDSystem(sf::RenderWindow &window) :
	m_window(window) // get render window for drawing to screen
{
	readFont(); // reads the font before using it
	m_text.setFont(m_font); // set the font
	m_text.setColor(sf::Color::Black); // set the color for text
}

void HUDSystem::configure(entityx::EventManager &eventManager)
{
	eventManager.subscribe<EvReportNode>(*this);// checks out data from EvReportNode and subscribes it here
}

void HUDSystem::receive(const EvReportNode& e) // Receives data from EvReportNode event
{
	m_index = e.m_index; // get the current index from the tank ai class
}

// Method to update the hud system and its displays
void HUDSystem::update(entityx::EntityManager& entities,
	entityx::EventManager& events,
	double dt)
{

	m_time += dt / 1000.f;	// getting the time in seconds

	 // Check if the current index is 18 and the last index is 19
	if (m_index == 18 && m_prevIndex == 19)
	{
		laps++; // increment laps
		m_timeTaken = m_time; // store the time in time taken
		m_time = 0; // reset the timer
	}
	// Check if its not the first lap and the current index is one and the last index is 0
	if (laps !=0 && m_index == 1 && m_prevIndex == 0) // avoided getting the time taken at the start
	{
		laps++; // increment laps
		m_timeTaken = m_time; // store the time in time taken
		m_time = 0; // reset the timer
	}

	// The Hud strings to display to screen
	m_text.setString("Time : " + std::to_string(m_time) +
		"\nTime taken : " + std::to_string(m_timeTaken)
		+ "\nCurrent Node:" + std::to_string(m_index) +
		"\nLap: " + std::to_string(laps));
	m_window.draw(m_text); // displays text to screen

	m_prevIndex = m_index; // get the previous index
}
// Method to read the font from folder
void HUDSystem::readFont()
{
	if (!m_font.loadFromFile("./resources/fonts/akashi.ttf"))// get font from directory
	{
		std::cout << "The font is not loaded!" << std::endl; // display this if font failed to load
	}
}