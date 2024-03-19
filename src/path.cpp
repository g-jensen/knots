#include "../headers/path.hpp"

void updatePath(std::vector<sf::VertexArray>& path,
                std::optional<sf::Vector2f>& lastPosition, 
                sf::Vector2f newPosition) {
  if (!lastPosition.has_value()) {
    path.push_back(line(newPosition,newPosition));
  } else {
    const float distanceThreshold = 10.f;
    if (distance(lastPosition.value(),newPosition) < distanceThreshold)
      return;
    path.push_back(line(lastPosition.value(),newPosition));
  }
  lastPosition = newPosition;
}

void connectEnds(std::vector<sf::VertexArray>& path) {
  if (path.size() < 2) 
    return;
  path.push_back(line(path.back()[1].position,path.front()[0].position));
}

void resetPath(std::vector<sf::VertexArray>& path, 
               std::optional<sf::Vector2f>& lastPosition, 
               sf::VertexArray* previousCross[2]) {
  path.clear();
  lastPosition.reset();
  previousCross[0] = nullptr;
  previousCross[1] = nullptr;
}