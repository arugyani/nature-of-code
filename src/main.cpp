#include <SFML/Graphics.hpp>
#include <iostream>

#include "Distribution/Distribution.h"
#include "Gaussian/Gaussian.h"
#include "Walker/Walker.h"

int main() {
  // ------------------------- INITIALIZE -------------------------
  sf::ContextSettings settings;
  settings.antialiasingLevel = 4;

  sf::Clock clock;
  sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game",
                          sf::Style::Default, settings);
  window.setVerticalSyncEnabled(true);
  bool focus = true;

  sf::RenderTexture renderTexture;
  renderTexture.create(800, 600);
  renderTexture.setSmooth(true);

  sf::Sprite renderSprite(renderTexture.getTexture());

  sf::Vector2i mouse;

  // ------------------------- INITIALIZE -------------------------

  // ------------------------- OBJECTS -------------------------
  Distribution distribution(renderTexture);

  while (window.isOpen()) {
    // ------------------------- UPDATE -------------------------
    sf::Time timer = clock.restart();
    float deltaTime = timer.asSeconds();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
      if (event.type == sf::Event::GainedFocus) focus = true;
      if (event.type == sf::Event::LostFocus) focus = false;
    }

    if (focus) mouse = sf::Mouse::getPosition(window);

    distribution.AcceptReject(deltaTime);
    // ------------------------- UPDATE -------------------------

    // ------------------------- RENDER -------------------------
    renderTexture.clear(sf::Color::Transparent);
    distribution.Draw();
    renderTexture.display();

    window.clear(sf::Color::White);
    window.draw(renderSprite);
    window.display();
    // ------------------------- RENDER ------------------------
  }

  return 0;
}