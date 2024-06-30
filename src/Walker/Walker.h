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

  float speed = 0.1;

 public:
  Walker(sf::RenderTarget& target);

  void Update(double deltaTime) override;
  void Draw() override;
};