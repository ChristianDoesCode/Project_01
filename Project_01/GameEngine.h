//gameengine.h
#pragma once
#include <SFML/Graphics.hpp>
#include "shape.h"
#include <iostream>

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void applyGameEngine(Shape& shape, int screenWidth, int screenHeight, sf::Clock& clock);
	void applyGravity(Shape& shape, int screenHeight, sf::Clock& clock);
	void applyForce(Shape& shape, int screenWidth, int screenHeight);
};
