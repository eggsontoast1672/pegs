#include <cstdio>
#include <cstdlib>
#include <vector>

#include <SFML/Graphics.hpp>

#include "peg.hpp"

int main(void)
{
    auto window = sf::RenderWindow(
        sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
        "Pegs",
        sf::Style::Close | sf::Style::Titlebar
    );
    
    // CPU usage goes through the roof without this
    window.setVerticalSyncEnabled(true);
    
    auto block_texture = sf::Texture();
    if (!block_texture.loadFromFile(
        "../assets/tiles.png",
        sf::IntRect(0, 0, 8, 8)
    )) {
        std::fprintf(stderr, "[ERROR] Failed to load texture. Exiting...\n");
        return EXIT_FAILURE;
    }

    auto sprite = sf::Sprite();

    sprite.setTexture(block_texture);
    sprite.setScale(TILE_SIZE / 8.0, TILE_SIZE / 8.0);

    auto peg = Peg(sf::Vector2f(1, 0), sprite);

    while (window.isOpen()) {
        auto event = sf::Event();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(0xb3be98ff));
        window.draw(peg);
        window.display();
    }

    return 0;
}
