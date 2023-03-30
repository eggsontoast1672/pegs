#ifndef PEGS_PLAYER_HPP
#define PEGS_PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "settings.hpp"

class Player : public sf::Drawable {
private:
  sf::Vector2f position;
  sf::Sprite sprite;

public:
  Player(sf::Vector2f position, sf::Sprite sprite);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void update(void);
};

#endif
