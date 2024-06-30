#include "Walker.h"

Walker::Walker(sf::RenderTarget& target) : Graphics(target) {
  this->position.x = target.getSize().x / 2;
  this->position.y = target.getSize().y / 2;

  shape.setRadius(1.f);
  shape.setFillColor(sf::Color::Black);
  shape.setPosition(position);
}

void Walker::Update(double deltaTime) {
  int xStep = (std::rand() % 3) - 1;
  int yStep = (std::rand() % 3) - 1;

  this->position.x += xStep * speed * deltaTime;
  this->position.y += yStep * speed * deltaTime;

  shape.setPosition(position);
}

void Walker::Draw() { target.draw(shape); }