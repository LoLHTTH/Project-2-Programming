#include "systems/AiControlSystem.h"


AiControlSystem::AiControlSystem()
{
}

void AiControlSystem::configure(entityx::EventManager& events)
{  
   events.subscribe<EvReportPlayerId>(*this);
   events.subscribe<entityx::ComponentAddedEvent<Ai>>(*this);
   events.subscribe<entityx::ComponentAddedEvent<Wall>>(*this);
   events.subscribe<entityx::ComponentAddedEvent<Node>>(*this);
}

void AiControlSystem::receive(const EvReportPlayerId& e)
{
	m_playerId = e.m_playerId;
}

void AiControlSystem::receive(const entityx::ComponentAddedEvent<Ai>& e)
{
    Ai::Handle ai = e.component;
    m_tankAi.reset(new TankAi(m_obstacles, ai->m_id));	// id of turret
}

void AiControlSystem::receive(const entityx::ComponentAddedEvent<Wall>& e)
{
	entityx::Entity ent = e.entity;
	Volume::Handle wallVol = ent.component<Volume>();
	Position::Handle wallPos = ent.component<Position>();
	Display::Handle wallDisplay = ent.component<Display>();
	
	sf::CircleShape circle(wallVol->m_box.getRect().width * 1.5f);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(wallPos->m_position);
	m_obstacles.push_back(circle);	
}

// Method to get the information of the nodes and make a circle out of it and store them in m_pts
void AiControlSystem::receive(const entityx::ComponentAddedEvent<Node>& e)
{
	entityx::Entity ent = e.entity;
	Volume::Handle nodeVol = ent.component<Volume>(); // get the volume of node
	Position::Handle nodePos = ent.component<Position>();// get the positions of node

	m_nodeIds.push_back(ent.id()); // add the nodes to m_nodeIds

	// Create a circle using the values of the nodes
	sf::CircleShape circle(nodeVol->m_box.getRect().width * 1.5f);
	circle.setOrigin(circle.getRadius(), circle.getRadius());
	circle.setPosition(nodePos->m_position);
	m_pts.push_back(circle); // store the circle data in m_pts
}

void AiControlSystem::update(entityx::EntityManager& entities,
                             entityx::EventManager& events,
                             double dt)
{
   Ai::Handle ai;

   for (entityx::Entity entity : entities.entities_with_components(ai))
   {
	   m_tankAi->update(m_playerId, 
		                    entity.id(),
							m_nodeIds.at(m_tankAi->getIndex()), // get the nodes at the current index
							entities, 
						  events,
							dt);
  
   }
}
