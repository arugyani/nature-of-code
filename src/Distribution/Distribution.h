#pragma once
#include "../Graphics/Graphics.h"

class Distribution : public Graphics {
 private:
  std::vector<sf::RectangleShape> counts;
  unsigned int range = 20;
  unsigned int maxHeight = 0;
  unsigned int leader = 0;

 public:
  Distribution(sf::RenderTarget& target);

  void Update(double deltaTime) override;
  void Draw() override;
};