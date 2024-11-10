
#include "pacman.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(670, 370), "Pac-man");
    sf::Clock zegar;

    sf::Texture textures;
    if(!textures.loadFromFile("textures/ghost_and_pacman_textures.png")) { return 1; }
    sf::Texture wall;
    if(!wall.loadFromFile("textures/wall.png")) { return 1; }

    //OBIEKT PacMana
    PacMan pacMan(textures,sf::Vector2f(323,263),sf::IntRect(14,54,49,54),"pacMan");

    //DODAWANIE DUCHÓW DO WEKTORA
    std::vector<std::unique_ptr<Characters>> vector_of_ghosts;
    vector_of_ghosts.emplace_back(std::make_unique<Ghosts>(textures,sf::Vector2f(292,141),sf::IntRect(323,51,55,55),"Red"));
    vector_of_ghosts.emplace_back(std::make_unique<Ghosts>(textures,sf::Vector2f(312,141),sf::IntRect(143,51,55,55),"Orange"));
    vector_of_ghosts.emplace_back(std::make_unique<Ghosts>(textures,sf::Vector2f(332,141),sf::IntRect(203,51,55,55),"Blue"));
    vector_of_ghosts.emplace_back(std::make_unique<Ghosts>(textures,sf::Vector2f(352,141),sf::IntRect(263,51,55,55),"Pink"));

    //DODAWANIE TEKSTUR
    pacMan.add_bits_of_texture(sf::IntRect(17,251,54,49));//up
    pacMan.add_bits_of_texture(sf::IntRect(12,125,53,50));//down
    pacMan.add_bits_of_texture(sf::IntRect(14,187,49,54));//left
    pacMan.add_bits_of_texture(sf::IntRect(14,54,49,54));//right
    pacMan.add_bits_of_texture(sf::IntRect(76,244,54,56));//pelny

    vector_of_ghosts[0]->add_bits_of_texture(sf::IntRect(263,272,55,55));//up     //red
    vector_of_ghosts[0]->add_bits_of_texture(sf::IntRect(143,124,55,55));//down
    vector_of_ghosts[0]->add_bits_of_texture(sf::IntRect(203,199,55,55));//left
    vector_of_ghosts[0]->add_bits_of_texture(sf::IntRect(323,51,55,55));//right
    vector_of_ghosts[0]->add_bits_of_texture(sf::IntRect(443,51,55,55));//umarnięty
    vector_of_ghosts[0]->add_bits_of_texture(sf::IntRect(383,51,55,55));//uciekający

    vector_of_ghosts[1]->add_bits_of_texture(sf::IntRect(143,272,55,55));//up     //orange
    vector_of_ghosts[1]->add_bits_of_texture(sf::IntRect(203,124,55,55));//down
    vector_of_ghosts[1]->add_bits_of_texture(sf::IntRect(323,199,55,55));//left
    vector_of_ghosts[1]->add_bits_of_texture(sf::IntRect(143,51,55,55));//right
    vector_of_ghosts[1]->add_bits_of_texture(sf::IntRect(443,51,55,55));//umarnięty
    vector_of_ghosts[1]->add_bits_of_texture(sf::IntRect(383,51,55,55));//uciekający

    vector_of_ghosts[2]->add_bits_of_texture(sf::IntRect(323,272,55,55));//up     //blue
    vector_of_ghosts[2]->add_bits_of_texture(sf::IntRect(263,124,55,55));//down
    vector_of_ghosts[2]->add_bits_of_texture(sf::IntRect(263,199,55,55));//left
    vector_of_ghosts[2]->add_bits_of_texture(sf::IntRect(203,51,55,55));//right
    vector_of_ghosts[2]->add_bits_of_texture(sf::IntRect(443,51,55,55));//umarnięty
    vector_of_ghosts[2]->add_bits_of_texture(sf::IntRect(383,51,55,55));//uciekający

    vector_of_ghosts[3]->add_bits_of_texture(sf::IntRect(203,272,55,55));//up     //pink
    vector_of_ghosts[3]->add_bits_of_texture(sf::IntRect(323,124,55,55));//down
    vector_of_ghosts[3]->add_bits_of_texture(sf::IntRect(143,199,55,55));//left
    vector_of_ghosts[3]->add_bits_of_texture(sf::IntRect(263,51,55,55));//right
    vector_of_ghosts[3]->add_bits_of_texture(sf::IntRect(443,51,55,55));//umarnięty
    vector_of_ghosts[3]->add_bits_of_texture(sf::IntRect(383,51,55,55));//uciekający

    //WEKTOR ŚCIAN
    std::vector<std::unique_ptr<Walls_and_balls>> vector_of_walls;
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(50,50),sf::IntRect(0,0,570,30)));//ściany zewnętrzne
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(50,50),sf::IntRect(0,0,30,270)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(50,290),sf::IntRect(0,0,570,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(590,50),sf::IntRect(0,0,30,270)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(260,110),sf::IntRect(0,0,30,90)));//pionowe //ściany wewnętrzne
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(380,110),sf::IntRect(0,0,30,90)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(470,170),sf::IntRect(0,0,30,90)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(170,170),sf::IntRect(0,0,30,90)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(110,110),sf::IntRect(0,0,120,30)));//poziome
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(260,110),sf::IntRect(0,0,60,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(350,110),sf::IntRect(0,0,60,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(440,110),sf::IntRect(0,0,120,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(260,170),sf::IntRect(0,0,150,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(80,170),sf::IntRect(0,0,60,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(170,170),sf::IntRect(0,0,60,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(440,170),sf::IntRect(0,0,60,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(530,170),sf::IntRect(0,0,60,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(110,230),sf::IntRect(0,0,30,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(230,230),sf::IntRect(0,0,30,60)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(290,230),sf::IntRect(0,0,90,30)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(410,230),sf::IntRect(0,0,30,60)));
    vector_of_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(530,230),sf::IntRect(0,0,30,30)));



    //WEKTOR MAŁYCH KULEK
    std::vector<std::unique_ptr<Walls_and_balls>> vector_of_small_balls;
    for(int i=0;i<7;i++){
        for(int j=0;j<17;j++){
            vector_of_small_balls.emplace_back(std::make_unique<Walls_and_balls>(textures,sf::Vector2f(92+j*30,92+i*30),sf::IntRect(38,70,12,12),sf::Vector2f(0.5,0.5)));
        }
    }

    //WEKTOR DUŻYCH KULEK
    std::vector<std::unique_ptr<Walls_and_balls>> vector_of_big_balls;
    vector_of_big_balls.emplace_back(std::make_unique<Walls_and_balls>(textures,sf::Vector2f(90,90),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));
    vector_of_big_balls.emplace_back(std::make_unique<Walls_and_balls>(textures,sf::Vector2f(90,269),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));
    vector_of_big_balls.emplace_back(std::make_unique<Walls_and_balls>(textures,sf::Vector2f(567,90),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));
    vector_of_big_balls.emplace_back(std::make_unique<Walls_and_balls>(textures,sf::Vector2f(567,269),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));
    vector_of_big_balls.emplace_back(std::make_unique<Walls_and_balls>(textures,sf::Vector2f(-50,-50),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = zegar.restart();

        for(auto &it : vector_of_ghosts){
            it->movement(elapsed,window);
            it->texture_animation(elapsed);
        }
        pacMan.movement(elapsed,window);
        pacMan.texture_animation(elapsed);
          //PacMan *pacMan = dynamic_cast<PacMan *>(vector_of_ghosts[0].get());
        pacMan.collision_with_big_balls(elapsed, vector_of_big_balls, vector_of_ghosts);
        pacMan.collision_with_small_balls(vector_of_small_balls);
          //pacMan.kolizja_z_duchami(vector_of_ghosts);
        pacMan.collision_with_walls(vector_of_walls, elapsed);


        window.clear(sf::Color (0,0,50));
        window.draw(pacMan);
        for(auto &it : vector_of_small_balls){
            window.draw(*it);
        }
        for(auto &it : vector_of_big_balls){
            window.draw(*it);
        }
        for(auto &it : vector_of_ghosts){
            window.draw(*it);
        }
        for(auto &it : vector_of_walls){
            window.draw(*it);
        }


        window.display();
    }

    return 0;
}

