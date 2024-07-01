#include <SFML/Graphics.hpp>
#include <vector>

class Walker : public sf::Drawable {
 public:
  // Constructor
  Walker(sf::RenderTarget& target);

  // Movement methods
  void MoveRandom(double deltaTime);
  void MoveRight(double deltaTime);
  void MoveToMouse(double deltaTime, sf::Vector2i mouse);
  void LevyFlight(double deltaTime);

 private:
  sf::RenderTarget& target;
  sf::CircleShape shape;
  sf::Vector2f position;
  const float speed = 100.0f;

  // Vertex array to store the history (trail) of the walker
  sf::VertexArray history;
  size_t vertexCount = 0;
  size_t head = 0;
  bool isFull = false;

  // Update the vertex array with the current position
  void update();

  // Normalize the direction vector
  sf::Vector2f NormDirection(const sf::Vector2f& start,
                             const sf::Vector2f& target) {
    sf::Vector2f direction(start.x - target.x, start.y - target.y);
    float distance =
        std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance == 0) return start;

    sf::Vector2f normalizedDirection = direction / distance;

    return normalizedDirection;
  }

  // Override the draw method from sf::Drawable
  virtual void draw(sf::RenderTarget& target,
                    sf::RenderStates states) const override;
};
