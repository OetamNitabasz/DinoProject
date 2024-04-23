#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"



float positionX, positionY;
float velocityX, velocityY;
float graivty = 0.5f;
float positionXCactus, positionYCactus;
void jump(float time) {
    positionX += velocityX * time;
    positionY += velocityY * time;
    velocityY += graivty * time;
    if (positionY > 1080 - 400) {
        positionY = 1080 - 400;
        velocityY = 0;
    }
}
void OnJumpKeyPressed() {
    velocityY = -12.0f;
}
void OnJumpKeyReleased() {
    if(velocityY < -6.0f) {
        velocityY = -6.0f;
    }
}
void moveForward(float speed) {
    positionX += speed;
}
void moveBack(sf::Sprite object, float speed) {
    positionXCactus -= speed;
}

/*void moveDown(sf::Sprite object, float goingBackSpeed) {
    positionY -= goingBackSpeed;
}
 */
int main() {
    int width = 1920;
    int height = 1080;

    sf::RenderWindow window(sf::VideoMode(width, height), "DinoProject",
                            sf::Style::Close | sf::Style::Resize);


    sf::Sprite dino;
    sf::Texture d;

    sf::Sprite ground;
    sf::Texture g;

    sf::Sprite background;
    sf::Texture b;

    sf::Sprite cactus;
    sf::Texture obstacle;

    if (!d.loadFromFile("C:\\Users\\mateu\\Downloads\\dino1.png")) {
        std::cerr << "Nie udalo sie wczytac zdjecia." << std::endl;
    }

    if(!g.loadFromFile("C:\\Users\\mateu\\Downloads\\ground1.png")) {
        std::cerr << "Nie udalo sie wczytac zdjecia podlogi." << std::endl;
    }

    if(!b.loadFromFile("C:\\Users\\mateu\\Downloads\\background.jpg")) {
        std::cerr << "Nie udalo sie wczytac zdjecia tla." << std::endl;
    }

    if(!obstacle.loadFromFile("C:\\Users\\mateu\\Downloads\\cactus.png")){
        std::cerr << "Nie udalo sie wczytac zdjecia przeszkody." << std::endl;
    }

    background.setTexture(b);
    //background.setPosition(0, window.getSize().y - background.getGlobalBounds().height);

    ground.setTexture(g);
    ground.setScale(1.0,0.4f);
    ground.setPosition(0, window.getSize().y - ground.getGlobalBounds().height);


    dino.setTexture(d);
    dino.setColor(sf::Color::Blue);
    dino.setScale(0.4, 0.4);
    positionX = 0;
    positionY = height - dino.getGlobalBounds().height * 0.4;

    cactus.setTexture(obstacle);
    cactus.setColor(sf::Color::Yellow);
    cactus.setScale(0.4,0.4);
    cactus.setPosition(window.getSize().x - cactus.getGlobalBounds().height,
                       window.getSize().y - cactus.getGlobalBounds().height - 180);
    positionXCactus = width - cactus.getGlobalBounds().width * 1.9;
    positionYCactus = height - cactus.getGlobalBounds().height * 1.9;


    while (window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed)
                window.close();
            if (evnt.type == sf::Event::KeyPressed) {
                if (evnt.key.code == sf::Keyboard::Space) {
                    OnJumpKeyPressed();
                }
            }

            if (evnt.type == sf::Event::KeyPressed) {
                if (evnt.key.code == sf::Keyboard::Right) {
                    moveForward(10.0f);
                }
            }

            /*if(evnt.type == sf::Event::KeyPressed) {
                if(evnt.key.code == sf::Keyboard::Left) {

                }
            }
             */

            if (evnt.type == sf::Event::KeyReleased) {
                if (evnt.key.code == sf::Keyboard::Space) {
                    OnJumpKeyReleased();
                }
            }
            /*if(evnt.type == sf::Event::KeyPressed) {
                if(evnt.key.code == sf::Keyboard::Down) {
                    moveDown(10);
                }
            }
             */
        }
        cactus.setPosition(positionXCactus, positionYCactus);
        moveBack(cactus, 0.1);

        sf::Time klatki = sf::seconds(1.f / 30.f);
        jump(klatki.asSeconds());


        dino.setPosition(positionX, positionY);



        window.clear();
        window.draw(background);
        window.draw(ground);
        window.draw(dino);
        window.draw(cactus);
        window.display();
    }

    return 0;
}
/*sprite.move(0, -60);
                sf::sleep(sf::milliseconds(20));
            } else {
            sf::sleep(sf::milliseconds(20));
            sprite.setPosition(pozycja);
                 */