#include "Distribution.h"

#include <iostream>

Distribution::Distribution(sf::RenderTarget& target) : Graphics(target) {
  this->counts.resize(range, sf::RectangleShape());

  float outlineThickness = 2;
  float totalWidth = target.getSize().x;
  float rectangleWidth = (totalWidth / range) - (outlineThickness * 2);
  float effectiveWidth = totalWidth / range;

  target.clear(sf::Color(41, 49, 61));

  for (int i = 0; i < range; i++) {
    counts[i].setSize(sf::Vector2f(rectangleWidth, 0));
    counts[i].setOrigin(0, 0);

    counts[i].setPosition(i * effectiveWidth + outlineThickness,
                          target.getSize().y);
    counts[i].setFillColor(sf::Color(191, 200, 214));
    counts[i].setOutlineThickness(outlineThickness);
    counts[i].setOutlineColor(sf::Color(31, 32, 33));
  }
}

void Distribution::Uniform(double deltaTime) {
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
    }
  }
}

void Distribution::AcceptReject(double deltaTime) {
  float accept_reject;

  while (true) {
    float r1 = (std::rand() % 1000) / 1000.0;
    float r2 = (std::rand() % 1000) / 1000.0;

    std::cout << r1 << ", " << r2 << std::endl;

    if (r2 < r1) {
      accept_reject = r1;
      break;
    }
  }

  unsigned int index = static_cast<int>(accept_reject * range);
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
    }
  }
}

void Distribution::Draw() {
  for (int i = 0; i < range; i++) {
    target.draw(counts[i]);
  }
}