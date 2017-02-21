#include "systems\HUDSystem.h"


void HUDSystem::receive(const EvInit& e)
{

}


void HUDSystem::update(entityx::EntityManager& entities, double dt)
{
	m_time += dt;
}