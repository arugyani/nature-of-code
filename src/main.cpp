#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "Distribution/Distribution.h"
#include "Gaussian/Gaussian.h"
#include "Walker/Walker.h"

int main() {
  // ------------------------- INITIALIZE -------------------------
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::Clock clock;
  sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game",
                          sf::Style::Default, settings);
  window.setVerticalSyncEnabled(true);
  bool focus = true;

  sf::Font font;
  if (!font.loadFromFile("assets/Bebas-Regular.ttf")) {
    std::cerr << "Failed to load font!" << std::endl;
    return -1;
  }

  // Frame rate
  const int frameBufferSize = 100;
  std::vector<float> frameTimes(frameBufferSize, 0.f);

  int frameIndex = 0;

  sf::Text fpsText;
  fpsText.setFont(font);
  fpsText.setCharacterSize(24);
  fpsText.setFillColor(sf::Color::Black);
  fpsText.setPosition(10.f, 10.f);

  sf::Vector2i mouse;

  // ------------------------- INITIALIZE -------------------------

  // ------------------------- OBJECTS -------------------------
  Walker walker(window);

  while (window.isOpen()) {
    // ------------------------- UPDATE -------------------------
    sf::Time timer = clock.restart();
    float deltaTime = timer.asSeconds();

    frameTimes[frameIndex] = deltaTime;
    frameIndex = (frameIndex + 1) % frameBufferSize;

    float averageFrameTime =
        std::accumulate(frameTimes.begin(), frameTimes.end(), 0.0f) /
        frameBufferSize;
    float averageFPS = 1.f / averageFrameTime;

    std::ostringstream ss;
    ss << static_cast<int>(averageFPS) << " FPS (avg over " << frameBufferSize
       << " frames)";
    fpsText.setString(ss.str());

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
      if (event.type == sf::Event::GainedFocus) focus = true;
      if (event.type == sf::Event::LostFocus) focus = false;
    }

    if (focus) mouse = sf::Mouse::getPosition(window);

    // ------------------------- UPDATE -------------------------
    walker.MoveToMouse(deltaTime, mouse);
    // walker.MoveRandom(deltaTime);
    // ------------------------- RENDER -------------------------
    window.clear(sf::Color::White);
    window.draw(walker);
    window.draw(fpsText);
    window.display();
    // ------------------------- RENDER ------------------------
  }

  return 0;
}