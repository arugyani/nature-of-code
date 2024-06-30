#include "Walker.h"

#include <iostream>

Walker::Walker(sf::RenderTarget& target) : Graphics(target) {
  this->position.x = target.getSize().x / 2;
  this->position.y = target.getSize().y / 2;

  shape.setRadius(2.f);
  shape.setFillColor(sf::Color(0, 0, 0));
  // shape.setOutlineThickness(2);
  // shape.setOutlineColor(sf::Color(27, 36, 36));
  shape.setPosition(position);
}

void Walker::MoveRandom(double deltaTime) {
  /* PURELY RANDOM MOVEMENT */
  int xStep = (std::rand() % 3) - 1;
  int yStep = (std::rand() % 3) - 1;

  this->position.x += xStep * speed * deltaTime;
  this->position.y += yStep * speed * deltaTime;

  shape.setPosition(position);
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

  shape.setPosition(position);
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

void Walker::LevyFlight(double deltaTime) {
  float random = static_cast<float>(std::rand() % 1000) / 1000.0;

  int xStep;
  int yStep;

  if (random < 0.01) {
    xStep = (std::rand() % 201) - 100;
    yStep = (std::rand() % 201) - 100;
  } else {
    xStep = (std::rand() % 3) - 1;
    yStep = (std::rand() % 3) - 1;
  }

  std::cout << xStep << ", " << yStep << std::endl;

  int newX = this->position.x + (xStep * speed * deltaTime);
  int newY = this->position.y + (yStep * speed * deltaTime);

  if (newX < 0 || newX > target.getSize().x) return;
  if (newY < 0 || newY > target.getSize().y) return;

  this->position.x += xStep * speed * deltaTime;
  this->position.y += yStep * speed * deltaTime;

  shape.setPosition(position);
}