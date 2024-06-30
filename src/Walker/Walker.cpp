#include "Walker.h"

#include <iostream>

Walker::Walker(sf::RenderTarget& target) : Graphics(target) {
  this->position.x = target.getSize().x / 2;
  this->position.y = target.getSize().y / 2;

  shape.setRadius(1.f);
  shape.setFillColor(sf::Color::Black);
  shape.setPosition(position);
}

void Walker::MoveRandom(double deltaTime) {
  /* PURELY RANDOM MOVEMENT */
  int xStep = (std::rand() % 3) - 1;
  int yStep = (std::rand() % 3) - 1;

  this->position.x += xStep * speed * deltaTime;
  this->position.y += yStep * speed * deltaTime;
}

void Walker::MoveRight(double deltaTime) {
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
}

void Walker::MoveToMouse(double deltaTime, sf::Vector2i mouse) {
  /* 50% CHANCE OF MOVING IN DIRECTION OF MOUSE */
  float random = static_cast<float>(std::rand() % 100) / 100.0;
  if (random < 0.5) {  // Move towards mouse
    sf::Vector2f direction =
        NormDirection(position, sf::Vector2f(mouse.x, mouse.y));

    float moveDistance = speed * deltaTime;
    sf::Vector2f moveVector = direction * moveDistance;

    this->position -= moveVector;
  } else {  // Move randomly
    int xStep = (std::rand() % 3) - 1;
    int yStep = (std::rand() % 3) - 1;

    this->position.x += xStep * speed * deltaTime;
    this->position.y += yStep * speed * deltaTime;
  }

  shape.setPosition(position);
}