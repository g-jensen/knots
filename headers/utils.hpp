#pragma once

#include <cmath>

#include <SFML/Graphics.hpp>

float distance(sf::Vector2f v1, sf::Vector2f v2);
sf::VertexArray line(sf::Vector2f pos1, sf::Vector2f pos2);