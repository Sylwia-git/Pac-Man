#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "characters.h"

class Ghosts : public Characters{
public:
    Ghosts(const sf::Texture &texture, const sf::Vector2f &position, const sf::IntRect &rectangle, const std::string &typ) : Characters(texture,position,rectangle,typ){}
    void add_bits_of_texture(sf::IntRect xxx);
    void ruch(const sf::Time &e,sf::RenderWindow &window);
    void animacja(const sf::Time &e);
    void kolizja_ze_scianiami(std::vector<std::unique_ptr<Walls_and_balls>> &v, const sf::Time &e);
};

