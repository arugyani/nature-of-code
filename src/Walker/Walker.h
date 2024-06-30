#pragma once
#include "../Graphics/Graphics.h"

/**
 * @class Walker
 * @brief A class that represents a walker which moves randomly on the screen.
 *
 * The Walker class handles the lgoic for a walker (small circle) that moves
 * randomly on the screen and draws itself on a given render texture.
 */
class Walker : public Graphics {
 private:
  sf::CircleShape shape;
  sf::Vector2f position;

  float speed = 100.0f;

  sf::Vector2f NormDirection(const sf::Vector2f& start,
                             const sf::Vector2f& target) {
    sf::Vector2f direction(start.x - target.x, start.y - target.y);
    float distance =
        std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance == 0) return start;

    sf::Vector2f normalizedDirection = direction / distance;

    return normalizedDirection;
  }

 public:
  Walker(sf::RenderTarget& target);

  void MoveRandom(double deltaTime);
  void MoveRight(double deltaTime);
  void MoveToMouse(double deltaTime, sf::Vector2i mouse);
  void LevyFlight(double deltaTime);

  void Draw() override { target.draw(shape); };
};