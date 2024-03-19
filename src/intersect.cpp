#include "../headers/intersect.hpp"

bool const onSegment(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) { 
  if (q.x < std::max(p.x, r.x) && q.x > std::min(p.x, r.x) && 
      q.y < std::max(p.y, r.y) && q.y > std::min(p.y, r.y)) 
      return true; 

  return false; 
} 
  
int const orientation(sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) { 
  int val = (q.y - p.y) * (r.x - q.x) - 
            (q.x - p.x) * (r.y - q.y); 

  if (val == 0) return 0;  // collinear 

  return (val > 0)? 1: 2; // clock or counterclock wise 
}

bool const doIntersect(const sf::VertexArray& line1, const sf::VertexArray& line2) {
  sf::Vector2f p1 = line1[0].position;
  sf::Vector2f q1 = line1[1].position;
  sf::Vector2f p2 = line2[0].position;
  sf::Vector2f q2 = line2[1].position;
  int o1 = orientation(p1, q1, p2); 
  int o2 = orientation(p1, q1, q2); 
  int o3 = orientation(p2, q2, p1); 
  int o4 = orientation(p2, q2, q1); 

  if (o1 != o2 && o3 != o4) 
    return true; 


  if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  if (o4 == 0 && onSegment(p2, q1, q2)) return true; 

  return false;
}

void crossLines(sf::VertexArray& overLine, sf::VertexArray& underLine) {
  underLine[0].color = sf::Color::Black;
  underLine[1].color = sf::Color::Black;
  overLine[0].color = sf::Color::White;
  overLine[1].color = sf::Color::White;
}

bool alreadyCrossed(sf::VertexArray& line) {
  if (line.getVertexCount() != 2)
    return false;
  return line[0].color == sf::Color::Black;
}

bool alreadyCrossed(sf::VertexArray& line1, sf::VertexArray& line2) {
  return alreadyCrossed(line1) || alreadyCrossed(line2);
}

void updateIntersections(std::vector<sf::VertexArray>& path, sf::VertexArray* previousCross[2]) {
  if (path.empty())
    return;
  sf::VertexArray* lastLine = &path.back();
  for (auto& line: path) {
    if (&line == lastLine || alreadyCrossed(line,*lastLine)) {
      continue;
    }
    if (path.size() >= 2) {
      sf::VertexArray* lastLastLine = lastLine - 1;
      if (&line == lastLastLine) {
        continue;
      }
    }
    if (doIntersect(line,*lastLine)) {
      previousCross[0] = &line;
      previousCross[1] = lastLine;
      crossLines(*lastLine,line);
      return;
    }
  }
}

void toggleCross(sf::VertexArray* previousCross[2]) {
  if (previousCross[0] == nullptr || previousCross[1] == nullptr)
    return;

  if (alreadyCrossed(*(previousCross[0]))) {
    crossLines(*(previousCross[0]),*(previousCross[1]));
  } else if (alreadyCrossed(*(previousCross[1]))) {
    crossLines(*(previousCross[1]),*(previousCross[0]));
  }
}