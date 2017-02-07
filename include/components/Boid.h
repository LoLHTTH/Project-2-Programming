#pragma once
#include "components\Path.h"
#include "utils/BTMath.h"
#include "entityx/Entity.h"
#include "components/Position.h"
#include <vector>
//#include <>

class Boid
{
public:
	sf::Vector2f pathFollowing(entityx::Entity::Id aiId,
		entityx::EntityManager& entities);

private:
	Path path;
	int currentNode;
};