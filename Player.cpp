//
// Created by mateu on 21.04.2024.
//

#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Player::Player() {
    sf::Sprite sprite;
    sf::Texture texture;
    //sprite.getGlobalBounds()
    if(!texture.loadFromFile("C:\\Users\\mateu\\Downloads\\dino1.png")) {
        std::cerr << "Nie udalo sie wczytac zdjecia." << std::endl;
    }
};