#include <SFML/Graphics.hpp>
#include <iostream>

#include "Distribution/Distribution.h"
#include "Walker/Walker.h"

int main() {
  // ------------------------- INITIALIZE -------------------------
  sf::ContextSettings settings;
  settings.antialiasingLevel = 8;

  sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game",
                          sf::Style::Default, settings);
  window.setVerticalSyncEnabled(true);

  sf::RenderTexture renderTexture;
  renderTexture.create(800, 600);

  sf::Sprite renderSprite(renderTexture.getTexture());

  sf::Clock clock;
  // ------------------------- INITIALIZE -------------------------

  // ------------------------- OBJECTS -------------------------
  Distribution distribution(renderTexture);

  while (window.isOpen()) {
    // ------------------------- UPDATE -------------------------
    sf::Time timer = clock.restart();
    float deltaTime = timer.asMilliseconds();

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    // ------------------------- UPDATE -------------------------
    distribution.Update(deltaTime);
    // ------------------------- RENDER -------------------------
    renderTexture.clear(sf::Color::White);
    distribution.Draw();
    renderTexture.display();

    window.clear(sf::Color::White);
    window.draw(renderSprite);
    window.display();
    // ------------------------- RENDER ------------------------
  }

  return 0;
}