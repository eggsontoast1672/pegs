#include "player.hpp"

Player::Player(sf::Vector2f position, sf::Sprite sprite)
    : position(position), sprite(sprite) {}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform.translate(
      sf::Vector2f(position.x * TILE_SIZE, position.y * TILE_SIZE));
  target.draw(sprite, states);
}

void Player::update(void) {
  // Nothing here yet
}
