#pragma once
#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"
#include "EntityCreator.h"

class HUDSystem
	: public entityx::System<HUDSystem>
	, public entityx::Receiver<EvInit>
{
public:
	void receive(const EvInit& e);
	void update(entityx::EntityManager& entities, double dt);
private:
	std::unique_ptr<TankAi> m_tankAi;
	float m_time;
};