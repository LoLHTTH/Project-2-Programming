#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Path
{
public:
	Path();
	~Path();
	void addNode(sf::Vector2f node);
	std::vector<sf::Vector2f> getNode();
private:
	std::vector<sf::Vector2f> m_nodes;
};