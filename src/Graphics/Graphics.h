#pragma once
#include <SFML/Graphics.hpp>

class Graphics {
 protected:
  sf::RenderTarget& target;

 public:
  Graphics(sf::RenderTarget& target) : target(target) {}
  virtual ~Graphics(){};

  virtual void Update(double deltaTime) = 0;
  virtual void Draw() = 0;
};