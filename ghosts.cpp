#include "ghosts.h"

void Ghosts::add_bits_of_texture(sf::IntRect xxx){
    bits_of_texture.emplace_back(xxx);
}

void Ghosts::movement(const sf::Time &e,sf::RenderWindow &window)
{

}
void Ghosts::collision_with_walls(std::vector<std::unique_ptr<Walls_and_balls>> &v, const sf::Time &e)
{

}

void Ghosts::texture_animation(const sf::Time &e)
{
    setScale(0.5, 0.5);
}
