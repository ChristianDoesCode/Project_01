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
	void applyGameEngine(Shape& shape, float deltaTime, int screenWidth, int screenHeight);
	void applyGravity(Shape& shape, float deltaTime, int screenWidth, int screenHeight);
};
