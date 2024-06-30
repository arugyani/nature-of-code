#include "Walker.h"

#include <iostream>

Walker::Walker(sf::RenderTarget& target) : Graphics(target) {
  this->position.x = target.getSize().x / 2;
  this->position.y = target.getSize().y / 2;

  shape.setRadius(1.f);
  shape.setFillColor(sf::Color::Black);
  shape.setPosition(position);
}

void Walker::Update(double deltaTime) {
  /* PURELY RANDOM MOVEMENT */
  // int xStep = (std::rand() % 3) - 1;
  // int yStep = (std::rand() % 3) - 1;

  // this->position.x += xStep * speed * deltaTime;
  // this->position.y += yStep * speed * deltaTime;

  /* TENDS TO MOVE RIGHT */
  float random = static_cast<float>(std::rand() % 10) / 10.0;
  if (random < 0.4) {
    this->position.x += speed * deltaTime;  // 40% chance to go right
  } else if (random < 0.6) {
    this->position.x -= speed * deltaTime;  // 20% chance to go left
  } else if (random < 0.8) {
    this->position.y += speed * deltaTime;  // 20% chance to go down
  } else {
    this->position.y -= speed * deltaTime;  // 20% chance to go up
  }

  shape.setPosition(position);
}

void Walker::Draw() { target.draw(shape); }