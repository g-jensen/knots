#pragma once

#include <cmath>
#include <optional>
#include <iostream>
#include <algorithm>

#include <SFML/Graphics.hpp>

static bool const onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r);
static int const orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r);
static bool const doIntersect(const sf::VertexArray& line1, const sf::VertexArray& line2);
static void crossLines(sf::VertexArray& overLine, sf::VertexArray& underLine);
static bool alreadyCrossed(sf::VertexArray& line);
static bool alreadyCrossed(sf::VertexArray& line1, sf::VertexArray& line2);

void updateIntersections(std::vector<sf::VertexArray>& path, sf::VertexArray* previousCross[2]);
void toggleCross(sf::VertexArray* previousCross[2]);