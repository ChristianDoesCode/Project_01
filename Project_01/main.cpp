//main.cpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameengine.h"
#include "gamecheck.h"
#include "background.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game Engine");
    window.setFramerateLimit(60);

    sf::Clock clock;

    Background background("background.jpg");

    Shape myObject;
    myObject.setIsPlayer(true);
    //myObject.setGravity(true);
    myObject.setImage("character.png");
    myObject.setSpriteTexture();
    myObject.setSize(1.0f, 1.0f);
    myObject.setPositionVector(100, 100);
    myObject.setViewBox(0,0);

    Shape bullet;
    bullet.setImage("can.png");
    bullet.setSpriteTexture();
    bullet.setSize(0.1f,0.1f);
    bullet.setPositionVector(100 + 100, 100 + 50);
    bullet.setXVelocity(5.0f);

    GameEngine* Engine = new GameEngine();
    GameCheck* Check = new GameCheck();
    
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Engine->applyGameEngine(myObject, SCREEN_WIDTH, SCREEN_HEIGHT, clock);
        Engine->applyGameEngine(bullet, SCREEN_WIDTH, SCREEN_HEIGHT, clock);
        Check->applyGameCheck(myObject, background);
        
        window.clear();
        background.draw(window);
        myObject.draw(window);
        bullet.draw(window);
        window.display();
    }
}
