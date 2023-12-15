//main.cpp
#include <iostream>
#include <SFML/Graphics.hpp>
#include "object.h"
#include "gameengine.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game Engine");
    window.setFramerateLimit(60);

    sf::RectangleShape rect;
    sf::Vector2f rectPosition(600, 350);

    rect.setPosition(rectPosition);
    rect.setSize(sf::Vector2f(100, 100));

    sf::Clock clock;

    Object myObject;
    myObject.setGravity(true);
    myObject.setImage("sprite.png");
    myObject.setSpriteTexture();
    myObject.setSize(0.1f, 0.1f);
    myObject.setPositionVector(100, 100);

    GameEngine* Engine = new GameEngine();

    

    
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Time calculation
        sf::Time dt = clock.restart();
        float deltaTime = dt.asSeconds();

        Engine->applyGameEngine(myObject, deltaTime, SCREEN_WIDTH, SCREEN_HEIGHT);

        rect.setPosition(rectPosition);

        window.clear();
        window.draw(rect);
        myObject.draw(window);
        window.display();
    }
}
