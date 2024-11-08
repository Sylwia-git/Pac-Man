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
    void movement(const sf::Time &e,sf::RenderWindow &window);
    void texture_animation(const sf::Time &e);
    void collision_with_walls(std::vector<std::unique_ptr<Walls_and_balls>> &v, const sf::Time &e);
};

