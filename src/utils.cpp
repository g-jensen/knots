#include "../headers/utils.hpp"

float distance(sf::Vector2f v1, sf::Vector2f v2) {
  float dy = v2.y - v1.y;
  float dx = v2.x - v1.x;
  return sqrt((dy * dy) + (dx * dx));
}

sf::VertexArray line(sf::Vector2f pos1, sf::Vector2f pos2) {
  sf::VertexArray line(sf::Lines,2);
  line[0].position = pos1;
  line[0].color  = sf::Color::White;
  line[1].position = pos2;
  line[1].color = sf::Color::White;
  return line;
}