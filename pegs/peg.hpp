#ifndef PEGS_PEG_HPP
#define PEGS_PEG_HPP

#include <SFML/Graphics.hpp>

#include "settings.hpp"

class Peg : public sf::Drawable {
    private:
        // Positions are stored not as pixel coordinates on the screen, but as
        // integer coordinates in the game world. Effectively, it's a 12 by 8
        // grid scaled up so you can see it without squinting. The x-coordinate
        // of any given object can be between 0 and 12 inclusive, and the
        // y-coordinate can be between 0 and 8 inclusive.
        sf::Vector2f position;
        sf::Sprite sprite;
    
    public:
        Peg(sf::Vector2f position, sf::Sprite sprite);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif
