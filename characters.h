#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "walls_and_balls.h"

class Characters : public sf::Sprite{
protected:
    std::string typ_;
    float velociety_x_;
    float velociety_y_;
public:
    std::vector<sf::IntRect> bits_of_texture;
    Characters(const sf::Texture &texture, const sf::Vector2f &position,const sf::IntRect &rectangle, const std::string &typ) : sf::Sprite(texture){
        setPosition(position);
        setTextureRect(rectangle);
        typ_=typ;
    }
    virtual void add_bits_of_texture(sf::IntRect xxx)=0;
    virtual void movement(const sf::Time &e,sf::RenderWindow &window)=0;
    virtual void texture_animation(const sf::Time &e)=0;
    virtual void collision_with_walls(std::vector<std::unique_ptr<Walls_and_balls>> &v, const sf::Time &e)=0;
};

