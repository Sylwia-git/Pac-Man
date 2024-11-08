#include "pacman.h"

void PacMan::add_bits_of_texture(sf::IntRect xxx){
    bits_of_texture.emplace_back(xxx);
}

void PacMan::movement(const sf::Time &e,sf::RenderWindow &window){

    auto guy_bounds = getGlobalBounds();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(guy_bounds.left > 0){
            left=1;
            right=0;
            up=0;
            down=0;
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(guy_bounds.left+guy_bounds.width < window.getSize().x){
            right=1;
            left=0;
            up=0;
            down=0;
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(guy_bounds.top> 0){
            up=1;
            left=0;
            right=0;
            down=0;
        }
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if(guy_bounds.top+guy_bounds.height < window.getSize().y){
            down=1;
            left=0;
            right=0;
            up=0;
        }
    }
    if(left==1){
        velociety_x=-70;
        velociety_y=0;
    }if(right==1){
        velociety_x=70;
        velociety_y=0;
    }if(up==1){
        velociety_x=0;
        velociety_y=-70;
    }if(down==1){
        velociety_x=0;
        velociety_y=70;
    }
        if(left==1||right==1||up==1||down==1){
            std::cout<<"left:"<<left<<std::endl<<"right:"<<right<<std::endl<<"up:"<<up<<std::endl<<"down:"<<down<<std::endl;
        }
    move(velociety_x * e.asSeconds(), velociety_y * e.asSeconds());
}


void PacMan::texture_animation(const sf::Time &e){
    auto b = getGlobalBounds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == sf::Keyboard::isKeyPressed(sf::Keyboard::Right)== sf::Keyboard::isKeyPressed(sf::Keyboard::Up)== sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
            ){
        animation_time = 0;
        setScale(0.5, 0.5);
        setPosition(b.left, b.top);
    }else{
        if(right==1){//sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            setTextureRect(bits_of_texture[3]);
        }
        else if(left==1){//sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            setTextureRect(bits_of_texture[2]);
        }
        else if(up==1){//sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            setTextureRect(bits_of_texture[0]);
        }
        else if(down==1){//sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            setTextureRect(bits_of_texture[1]);
        }


        if(animation_time < 2.0){
            animation_time += 18 * e.asSeconds();
        }else{
            animation_time = 0.0;
        }
        if(animation_time < 0.5){
            setTextureRect(bits_of_texture[4]);
        }
    }
}

void PacMan::collision_with_walls(std::vector<std::unique_ptr<Walls_and_balls>> &v, const sf::Time &e){
    grounded = false;
    auto playerBounds = getGlobalBounds();
    auto playerBoundsNext = getGlobalBounds();
    playerBoundsNext.left = getPosition().x + velociety_x * e.asSeconds();
    playerBoundsNext.top = getPosition().y + velociety_y * e.asSeconds();

    for (auto& wall : v) {

        auto wallBounds = wall->getGlobalBounds();
        if (wallBounds.intersects(playerBoundsNext))
        {

            //Bottom collision
            if (playerBounds.top < wallBounds.top
                && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left
                )
            {
                velociety_y = 0;
                setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
                grounded = true;
            }

            //Top Collision
            else if (playerBounds.top > wallBounds.top
                && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left
                )
            {
                velociety_y = 0;
                setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
            }

            //Right collisin
            if (playerBounds.left < wallBounds.left
                && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top
                )
            {
                velociety_x = 0;
                setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
            }

            //Left Collision
            else if (playerBounds.left > wallBounds.left
                && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                && playerBounds.top < wallBounds.top + wallBounds.height
                && playerBounds.top + playerBounds.height > wallBounds.top
                )
            {
                velociety_x = 0;
                setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
            }
        }

              if(playerBounds.top+playerBounds.height>600)
              {
                 velociety_y = 0;
                 setPosition(playerBounds.left, 600 - playerBounds.height);
                 grounded=true;

              }
    }
    move(velociety_x * e.asSeconds(), velociety_y * e.asSeconds());
}


void PacMan::collision_with_big_balls(const sf::Time &e, std::vector<std::unique_ptr<Walls_and_balls>> &v, const std::vector<std::unique_ptr<Characters>> &v_ghosts){
    for(int i=0; i<v.size(); i++){
        auto kulka =v[i]->getGlobalBounds();
        if(getGlobalBounds().intersects(kulka)){
            v.erase(v.begin()+i);//znika
            points+=100;
            collision_with_big_ball_=1;
        }
        if(collision_with_big_ball_==1){
            std::cout<<"kolizja";
            if(time_of_collision_with_big_ball_ < 10.0){
                time_of_collision_with_big_ball_ += 10 * e.asSeconds();
            }else{
                time_of_collision_with_big_ball_ = 0.0;
                collision_with_big_ball_ = 0;
            }
            //zmiana tekstury duchów
            for(int i=0; i<v_ghosts.size(); i++){
                v_ghosts[i]->setTextureRect(v_ghosts[i]->bits_of_texture[5]);
            }
        }
    }
}

void PacMan::collision_with_small_balls(std::vector<std::unique_ptr<Walls_and_balls>> &v){
    for(int i=0; i<v.size(); i++){
        auto kulka =v[i]->getGlobalBounds();
        if(getGlobalBounds().intersects(kulka)){//jeżeni kolizja z postacią
            v.erase(v.begin()+i);//znika
            points+=10;
        }
    }
}



void collision_with_ghosts(std::vector<std::unique_ptr<Characters>> &v){

}




