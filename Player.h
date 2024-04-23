//
// Created by mateu on 21.04.2024.
//

#ifndef DINOPROJECT_PLAYER_H
#define DINOPROJECT_PLAYER_H
#define HEIGHT_STAND 66
#define CROUCH_STAND 55
#define JUMP_POWER 2000
#define FALL_SPEED 10000
#define START_POSITION_X 100
#define START_POSITION_Y 300



#include <SFML/Graphics.hpp>
class Player {
    sf::RectangleShape self;
    Player();
};


#endif //DINOPROJECT_PLAYER_H
