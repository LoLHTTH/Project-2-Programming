#include "components\Boid.h"

sf::Vector2f Boid::pathFollowing(entityx::Entity::Id aiId,
	entityx::EntityManager& entities)
{
	sf::Vector2f target;

	//if (path != null)
	{
		entityx::Entity aiTank = entities.get(aiId);
		Position::Handle aiPos = aiTank.component<Position>();

		std::vector<sf::Vector2f> nodes = path.getNode();
		target = nodes[currentNode];
		if (Math::distance(aiPos->m_position, target) <= 10) {
			currentNode += 1;
			if (currentNode >= nodes.size()) {
				currentNode = nodes.size() - 1;
			}
		}
	}
	return sf::Vector2f(0, 1);
}