//gameengine.cpp
#include "GameEngine.h"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::applyGameEngine(Shape& shape, float deltaTime, int screenWidth, int screenHeight)
{
	this->applyGravity(shape, deltaTime, screenWidth, screenHeight);
}

void GameEngine::applyGravity(Shape& shape, float deltaTime, int screenWidth, int screenHeight)
{
	if (!(shape.getPositionY() >= screenHeight - 100))
	{
		shape.setPositionVector(shape.getPositionX(), (shape.getPositionY() + 10.0f * deltaTime));
		std::cout << shape.getPositionY() + 100.0f * deltaTime;
	}
}
