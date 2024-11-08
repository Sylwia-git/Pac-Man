/*#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}*/

#include "pacman.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(670, 370), "Pac-man");
    sf::Clock zegar;

    sf::Texture tekstury;
    if(!tekstury.loadFromFile("tekstury/teksturaaa.png")) { return 1; }
    sf::Texture wall;
    if(!wall.loadFromFile("tekstury/wall.png")) { return 1; }

    //PACMAN
    PacMan PC(tekstury,sf::Vector2f(0,50),sf::IntRect(14,54,49,54),"PC");


    //DODAWANIE Duchów DO WEKTORA
    std::vector<std::unique_ptr<Characters>> vec;
    vec.emplace_back(std::make_unique<Ghosts>(tekstury,sf::Vector2f(292,141),sf::IntRect(323,51,55,55),"Red"));
    vec.emplace_back(std::make_unique<Ghosts>(tekstury,sf::Vector2f(312,141),sf::IntRect(143,51,55,55),"Orange"));
    vec.emplace_back(std::make_unique<Ghosts>(tekstury,sf::Vector2f(332,141),sf::IntRect(203,51,55,55),"Blue"));
    vec.emplace_back(std::make_unique<Ghosts>(tekstury,sf::Vector2f(352,141),sf::IntRect(263,51,55,55),"Pink"));

    //DODAWANIE TEKSTUR
    PC.add_bits_of_texture(sf::IntRect(17,251,54,49));//up
    PC.add_bits_of_texture(sf::IntRect(12,125,53,50));//down
    PC.add_bits_of_texture(sf::IntRect(14,187,49,54));//left
    PC.add_bits_of_texture(sf::IntRect(14,54,49,54));//right
    PC.add_bits_of_texture(sf::IntRect(76,244,54,56));//pelny

    vec[0]->add_bits_of_texture(sf::IntRect(263,272,55,55));//up     //red
    vec[0]->add_bits_of_texture(sf::IntRect(143,124,55,55));//down
    vec[0]->add_bits_of_texture(sf::IntRect(203,199,55,55));//left
    vec[0]->add_bits_of_texture(sf::IntRect(323,51,55,55));//right
    vec[0]->add_bits_of_texture(sf::IntRect(443,51,55,55));//umarnięty
    vec[0]->add_bits_of_texture(sf::IntRect(383,51,55,55));//uciekający

    vec[1]->add_bits_of_texture(sf::IntRect(143,272,55,55));//up     //orange
    vec[1]->add_bits_of_texture(sf::IntRect(203,124,55,55));//down
    vec[1]->add_bits_of_texture(sf::IntRect(323,199,55,55));//left
    vec[1]->add_bits_of_texture(sf::IntRect(143,51,55,55));//right
    vec[1]->add_bits_of_texture(sf::IntRect(443,51,55,55));//umarnięty
    vec[1]->add_bits_of_texture(sf::IntRect(383,51,55,55));//uciekający

    vec[2]->add_bits_of_texture(sf::IntRect(323,272,55,55));//up     //blue
    vec[2]->add_bits_of_texture(sf::IntRect(263,124,55,55));//down
    vec[2]->add_bits_of_texture(sf::IntRect(263,199,55,55));//left
    vec[2]->add_bits_of_texture(sf::IntRect(203,51,55,55));//right
    vec[2]->add_bits_of_texture(sf::IntRect(443,51,55,55));//umarnięty
    vec[2]->add_bits_of_texture(sf::IntRect(383,51,55,55));//uciekający

    vec[3]->add_bits_of_texture(sf::IntRect(203,272,55,55));//up     //pink
    vec[3]->add_bits_of_texture(sf::IntRect(323,124,55,55));//down
    vec[3]->add_bits_of_texture(sf::IntRect(143,199,55,55));//left
    vec[3]->add_bits_of_texture(sf::IntRect(263,51,55,55));//right
    vec[3]->add_bits_of_texture(sf::IntRect(443,51,55,55));//umarnięty
    vec[3]->add_bits_of_texture(sf::IntRect(383,51,55,55));//uciekający

    //WEKTOR ŚCIAN
    std::vector<std::unique_ptr<Walls_and_balls>> v_walls;
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(50,50),sf::IntRect(0,0,570,30)));//ściany zewnętrzne
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(50,50),sf::IntRect(0,0,30,270)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(50,290),sf::IntRect(0,0,570,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(590,50),sf::IntRect(0,0,30,270)));

    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(260,110),sf::IntRect(0,0,30,90)));//pionowe //ściany wewnętrzne
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(380,110),sf::IntRect(0,0,30,90)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(470,170),sf::IntRect(0,0,30,90)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(170,170),sf::IntRect(0,0,30,90)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(110,110),sf::IntRect(0,0,120,30)));//poziome
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(260,110),sf::IntRect(0,0,60,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(350,110),sf::IntRect(0,0,60,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(440,110),sf::IntRect(0,0,120,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(260,170),sf::IntRect(0,0,150,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(80,170),sf::IntRect(0,0,60,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(170,170),sf::IntRect(0,0,60,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(440,170),sf::IntRect(0,0,60,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(530,170),sf::IntRect(0,0,60,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(110,230),sf::IntRect(0,0,30,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(230,230),sf::IntRect(0,0,30,60)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(290,230),sf::IntRect(0,0,90,30)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(410,230),sf::IntRect(0,0,30,60)));
    v_walls.emplace_back(std::make_unique<Walls_and_balls>(wall,sf::Vector2f(530,230),sf::IntRect(0,0,30,30)));



    //WEKTOR MAŁYCH KULEK
    std::vector<std::unique_ptr<Walls_and_balls>> v_small_balls;
    for(int i=0;i<7;i++){
        for(int j=0;j<17;j++){
            v_small_balls.emplace_back(std::make_unique<Walls_and_balls>(tekstury,sf::Vector2f(92+j*30,92+i*30),sf::IntRect(38,70,12,12),sf::Vector2f(0.5,0.5)));
        }
    }

    //WEKTOR DUŻYCH KULEK
    std::vector<std::unique_ptr<Walls_and_balls>> v_big_balls;
    v_big_balls.emplace_back(std::make_unique<Walls_and_balls>(tekstury,sf::Vector2f(90,90),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));
    v_big_balls.emplace_back(std::make_unique<Walls_and_balls>(tekstury,sf::Vector2f(90,269),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));
    v_big_balls.emplace_back(std::make_unique<Walls_and_balls>(tekstury,sf::Vector2f(567,90),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));
    v_big_balls.emplace_back(std::make_unique<Walls_and_balls>(tekstury,sf::Vector2f(567,269),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));
    v_big_balls.emplace_back(std::make_unique<Walls_and_balls>(tekstury,sf::Vector2f(-50,-50),sf::IntRect(274,342,26,26),sf::Vector2f(0.5,0.5)));



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time elapsed = zegar.restart();

        for(auto &it : vec){
            it->ruch(elapsed,window);
            it->animacja(elapsed);
        }
        PC.ruch(elapsed,window);
        PC.animacja(elapsed);
        //PacMan *pc = dynamic_cast<PacMan *>(vec[0].get());
        PC.kolizja_z_duzymi_kulkami(elapsed, v_big_balls, vec);
        PC.kolizja_z_malymi_kulkami(v_small_balls);
        //PC.kolizja_z_duchami(vec);
        PC.kolizja_ze_scianiami(v_walls, elapsed);



        window.clear(sf::Color (0,0,50));

        for(auto &it : v_small_balls){
            window.draw(*it);
        }
        for(auto &it : v_big_balls){
            window.draw(*it);
        }
        for(auto &it : vec){
            window.draw(*it);
        }
        for(auto &it : v_walls){
            window.draw(*it);
        }
        window.draw(PC);


        window.display();
    }

    return 0;
}

