#include "Gaussian.h"

void Gaussian::Update() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    target.clear(sf::Color::White);
    count = 0;
  }
}

void Gaussian::Draw() {
  if (count <= range) {
    double number = norm(generator);

    double min = mean - 3 * stddev;
    double max = mean + 3 * stddev;

    double scaled_number = (number - min) / (max - min) * target.getSize().x;

    sf::CircleShape circle;
    circle.setRadius(20.f);
    circle.setPosition(scaled_number, target.getSize().y / 2 - 10);
    circle.setFillColor(sf::Color(0, 0, 0, 10));

    target.draw(circle);

    ++count;
  }
}