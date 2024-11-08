#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "ghosts.h"


class PacMan : public Characters{
    float time_animation;
    int punkty=0;
    bool kolizja_z_duza_kulka_=0;
    float czas_kolizji_z_duza_kulka_;
    bool grounded = false;
    bool left=0 ,right=0, up=0, down=0;
public:
    float v_x;
    float v_y;
    PacMan(const sf::Texture &texture, const sf::Vector2f &position, const sf::IntRect &rectangle, const std::string &typ) : Characters(texture,position,rectangle,typ){}
    void add_bits_of_texture(sf::IntRect xxx);
    void ruch(const sf::Time &e,sf::RenderWindow &window);
    void animacja(const sf::Time &e);
    void kolizja_ze_scianiami(std::vector<std::unique_ptr<Walls_and_balls>> &v, const sf::Time &e);
    void kolizja_z_duzymi_kulkami(const sf::Time &e, std::vector<std::unique_ptr<Walls_and_balls>> &v, const std::vector<std::unique_ptr<Characters>> &v_ghosts);
    void kolizja_z_malymi_kulkami(std::vector<std::unique_ptr<Walls_and_balls>> &v);
    void kolizja_z_duchami(std::vector<std::unique_ptr<Characters>> &v);
};
