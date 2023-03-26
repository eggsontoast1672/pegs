#include <SFML/Graphics.hpp>

int main(void)
{
    auto window = sf::RenderWindow(sf::VideoMode(800, 600), "Pegs", sf::Style::Close | sf::Style::Titlebar);
    auto texture = sf::Texture();
    auto sprite = sf::Sprite();

    texture.loadFromFile("assets/tiles.png", sf::IntRect(0, 0, 8, 8));
    sprite.setTexture(texture);

    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(0xb3be98ff));
        window.draw(sprite);
        window.display();
    }

    return 0;
}
