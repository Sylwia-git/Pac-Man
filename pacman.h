#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "ghosts.h"


class PacMan : public Characters{
    float animation_time=0;
    int points=0;
    bool collision_with_big_ball_=0;
    float time_of_collision_with_big_ball_;
    bool grounded = false;
    bool left=0 ,right=0, up=0, down=0;
public:
    float velociety_x;
    float velociety_y;
    PacMan(const sf::Texture &texture, const sf::Vector2f &position, const sf::IntRect &rectangle, const std::string &typ) : Characters(texture,position,rectangle,typ){}
    void add_bits_of_texture(sf::IntRect xxx);
    void movement(const sf::Time &e,sf::RenderWindow &window);
    void texture_animation(const sf::Time &e);
    void collision_with_walls(std::vector<std::unique_ptr<Walls_and_balls>> &v, const sf::Time &e);
    void collision_with_big_balls(const sf::Time &e, std::vector<std::unique_ptr<Walls_and_balls>> &v, const std::vector<std::unique_ptr<Characters>> &v_ghosts);
    void collision_with_small_balls(std::vector<std::unique_ptr<Walls_and_balls>> &v);
    void collision_with_ghosts(std::vector<std::unique_ptr<Characters>> &v);
};
