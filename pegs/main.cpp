#include <cstdio>
#include <cstdlib>
#include <vector>

#include <SFML/Graphics.hpp>

#include "peg.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pegs", sf::Style::Close | sf::Style::Titlebar);

    // CPU usage goes through the roof without this
    window.setVerticalSyncEnabled(true);

    sf::Texture block_texture;
    if (!block_texture.loadFromFile(
        "../assets/tiles.png",
        sf::IntRect(0, 0, 8, 8)
    )) {
        std::fprintf(stderr, "[ERROR] Failed to load texture. Exiting...\n");
        return EXIT_FAILURE;
    }

    sf::Sprite sprite;

    sprite.setTexture(block_texture);
    sprite.setScale(TILE_SIZE / 8.0, TILE_SIZE / 8.0);

    std::vector<Peg> pegs;
    for (int i = 0; i < 12; ++i) // Top
        pegs.emplace_back(sf::Vector2f(i, 0), sprite);
    for (int i = 0; i < 12; ++i) // Bottom
        pegs.emplace_back(sf::Vector2f(i, 7), sprite);
    for (int i = 1; i < 7; ++i) // Left
        pegs.emplace_back(sf::Vector2f(0, i), sprite);
    for (int i = 1; i < 7; ++i) // Right
        pegs.emplace_back(sf::Vector2f(11, i), sprite);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(0xb3be98ff));

        for (const Peg &peg : pegs)
            window.draw(peg);

        window.display();
    }

    return EXIT_SUCCESS;
}
