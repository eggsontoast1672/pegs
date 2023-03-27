#include "peg.hpp"

Peg::Peg(sf::Vector2f position, sf::Sprite sprite)
    : position(position), sprite(sprite)
{}

void Peg::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform.translate(sf::Vector2f(
        position.x * TILE_SIZE,
        position.y * TILE_SIZE
    ));
    target.draw(sprite, states);
}
