#pragma once
#include <random>

#include "../Graphics/Graphics.h"

class Gaussian : public Graphics {
 private:
  double mean = 10.0;
  double stddev = 2.0;

  unsigned int const range = 1000;
  unsigned int count = 0;

  std::random_device rd;
  std::mt19937 generator{rd()};
  std::normal_distribution<double> norm{mean, stddev};

 public:
  Gaussian(sf::RenderTarget& target) : Graphics(target) {}

  void Update();
  void Draw() override;
};