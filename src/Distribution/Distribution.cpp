#include "Distribution.h"

#include <iostream>

Distribution::Distribution(sf::RenderTarget& target) : Graphics(target) {
  this->counts.resize(range, sf::RectangleShape());

  float outlineThickness = 2;
  float rectangleWidth = target.getSize().x / range;

  for (int i = 0; i < range; i++) {
    counts[i].setSize(sf::Vector2f(rectangleWidth, 0));
    counts[i].setPosition(i * rectangleWidth, target.getSize().y);
    counts[i].setFillColor(sf::Color::Black);
  }
}

void Distribution::Update(double deltaTime) {
  unsigned int index = (std::rand() % range);
  unsigned int speed = 5;

  if (index < range && maxHeight <= target.getSize().y) {
    sf::Vector2f size = counts[index].getSize();
    size.y += speed;

    sf::Vector2f position = counts[index].getPosition();
    position.y -= speed;

    counts[index].setSize(size);
    counts[index].setPosition(position);

    if (size.y > maxHeight) {
      maxHeight = size.y + 5;
      leader = index;
    }
  }
}

void Distribution::Draw() {
  for (int i = 0; i < range; i++) {
    if (i != leader)
      counts[i].setFillColor(sf::Color::Black);
    else
      counts[i].setFillColor(sf::Color::Green);

    target.draw(counts[i]);
  }
}