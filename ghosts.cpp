#include "ghosts.h"

void Ghosts::add_bits_of_texture(sf::IntRect xxx){
    bits_of_texture.emplace_back(xxx);
}

void Ghosts::ruch(const sf::Time &e,sf::RenderWindow &window)
{

}
void Ghosts::kolizja_ze_scianiami(std::vector<std::unique_ptr<Walls_and_balls>> &v, const sf::Time &e)
{

}

void Ghosts::animacja(const sf::Time &e)
{
    setScale(0.5, 0.5);
}
