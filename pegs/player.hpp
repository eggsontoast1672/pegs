#ifndef PEGS_PLAYER_HPP
#define PEGS_PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
    private:
        sf::Vector2f position;
        sf::Sprite sprite;

    public:
        Player();

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif
