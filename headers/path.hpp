#pragma once

#include <cmath>
#include <optional>
#include <iostream>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "utils.hpp"

void updatePath(std::vector<sf::VertexArray>& path,
                std::optional<sf::Vector2f>& lastPosition, 
                sf::Vector2f newPosition);
void connectEnds(std::vector<sf::VertexArray>& path);
void resetPath(std::vector<sf::VertexArray>& path, 
               std::optional<sf::Vector2f>& lastPosition, 
               sf::VertexArray* previousCross[2]);