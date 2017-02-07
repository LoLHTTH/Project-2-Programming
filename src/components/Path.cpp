#include "components\Path.h"

Path::Path()
{
	//m_nodes = std::vector<sf::Vector2f>;
}

Path::~Path()
{

}

void Path::addNode(sf::Vector2f node)
{
	//m_node.push(node);
	m_nodes.push_back(node);
}

std::vector<sf::Vector2f> Path::getNode()
{
	return m_nodes;
}