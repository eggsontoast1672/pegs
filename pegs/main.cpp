#include <iostream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>

#include "peg.hpp"
#include "player.hpp"
#include "settings.hpp"

static sf::Texture
load_texture_from_file(const std::string &filename,
                       const sf::IntRect &area = sf::IntRect()) {
  sf::Texture texture;
  if (!texture.loadFromFile(filename, area)) {
    std::cerr << "[ERROR] Failed to load texture. Exiting...\n";
    exit(EXIT_FAILURE);
  }
  return texture;
}

int main(void) {
  sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pegs",
                          sf::Style::Close | sf::Style::Titlebar);

  window.setVerticalSyncEnabled(true);

  sf::Texture tilemap = load_texture_from_file("../assets/tiles.png");

  sf::Sprite wall(tilemap, sf::IntRect(0, 0, 8, 8));
  sf::Sprite player_sprite(tilemap, sf::IntRect(8, 0, 8, 8));

  wall.setScale(TILE_SIZE / 8.0, TILE_SIZE / 8.0);
  player_sprite.setScale(TILE_SIZE / 8.0, TILE_SIZE / 8.0);

  std::vector<Peg> pegs;

  for (int i = 0; i < 12; ++i) {
    pegs.emplace_back(sf::Vector2f(i, 0), wall);
  }
  for (int i = 0; i < 12; ++i) {
    pegs.emplace_back(sf::Vector2f(i, 7), wall);
  }
  for (int i = 1; i < 7; ++i) {
    pegs.emplace_back(sf::Vector2f(0, i), wall);
  }
  for (int i = 1; i < 7; ++i) {
    pegs.emplace_back(sf::Vector2f(11, i), wall);
  }

  Player player(sf::Vector2f(3, 3), player_sprite);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    player.update();

    window.clear(sf::Color(0xb3be98ff));
    for (const Peg &peg : pegs) {
      window.draw(peg);
    }
    window.draw(player_sprite);
    window.display();
  }

  return EXIT_SUCCESS;
}
