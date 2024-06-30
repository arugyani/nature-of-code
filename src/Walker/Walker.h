#pragma once
#include <SFML/Graphics.hpp>

/**
 * @class Walker
 * @brief A class that represents a walker which moves randomly on the screen.
 *
 * The Walker class handles the lgoic for a walker (small circle) that moves
 * randomly on the screen and draws itself on a given render texture.
 */
class Walker {
 private:
  sf::CircleShape shape;
  sf::Vector2f position;

  sf::RenderTarget& target;

  float speed = 0.1;

 public:
  Walker(sf::RenderTarget& target);

  void Load();
  void Update(double deltaTime);
  void Draw();
};