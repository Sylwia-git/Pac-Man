#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>

class Walls_and_balls : public sf::Sprite{
public:
    Walls_and_balls(const sf::Texture &texture, const sf::Vector2f &position,const sf::IntRect &rectangle, const sf::Vector2f &scale=sf::Vector2f(1,1)) : sf::Sprite(texture){
        setPosition(position);
        setTextureRect(rectangle);
        setScale(scale);
    }
};

