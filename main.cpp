#include <cmath>
#include <optional>
#include <iostream>
#include <algorithm>

#include <SFML/Graphics.hpp>

#include "headers/utils.hpp"
#include "headers/intersect.hpp"
#include "headers/path.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Knot");

  std::vector<sf::VertexArray> path;
  std::optional<sf::Vector2f> lastPosition;

  sf::VertexArray* previousCross[2] = {nullptr,nullptr};

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      if (event.type == sf::Event::MouseButtonPressed) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
          connectEnds(path);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
          resetPath(path,lastPosition,previousCross);
      }
      if (event.type == sf::Event::MouseMoved) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          updatePath(path,lastPosition,(sf::Vector2f)sf::Mouse::getPosition(window));
          updateIntersections(path,previousCross);
        }
      }
      if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
          toggleCross(previousCross);
      }
    }

    window.clear(sf::Color::Black);

    for (auto& r: path)
      window.draw(r);

    window.display();
  }

  return 0;
}