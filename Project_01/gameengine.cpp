//gameengine.cpp
#include "GameEngine.h"

GameEngine::GameEngine()
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::applyGameEngine(Shape& shape, int screenWidth, int screenHeight, sf::Clock& clock)
{
	//this->applyGravity(shape, screenHeight, clock);
	this->applyForce(shape, screenWidth, screenHeight);
}

void GameEngine::applyGravity(Shape& shape, int screenHeight, sf::Clock& clock)
{
	/*
	if (shape.getYVelocity() < 0)
	{
		clock.restart();
	}
	*/
	if (!(shape.getPositionY() >= screenHeight - 100))
	{
		shape.setYVelocity(shape.getYVelocity() + 9.8f * clock.getElapsedTime().asSeconds());
	}
	else
	{
		clock.restart();
	}
}

void GameEngine::applyForce(Shape& shape, int screenWidth, int screenHeight)
{
	if (!(shape.getPositionX() >= screenWidth - 100) && !(shape.getPositionX() <= 0))
	{
		shape.setPositionVector(shape.getPositionX() + shape.getXVelocity(), shape.getPositionY());
	}
	//If the object is going to fast makes sure it does not go past the sides of the screen
	else if ((shape.getXVelocity() >= (screenWidth - 100) - (shape.getPositionX() - 100)))
	{
		std::cout << "First else if loop ran!";
		shape.setPositionVector(shape.getPositionX() + (screenWidth - 100) - shape.getPositionX(), shape.getPositionY());
	}
	if (!(shape.getPositionY() >= screenHeight - 100) && !(shape.getPositionY() <= 0))
	{
		shape.setPositionVector(shape.getPositionX(), shape.getPositionY() + shape.getYVelocity());
	}
	//If the object is going to fast makes sure it does not go past the bottom of the screen
	else if ((shape.getYVelocity() >= (screenHeight - 100) - (shape.getPositionY() - 100)))
	{
		shape.setPositionVector(shape.getPositionX(), shape.getPositionY() + (screenHeight - 100) - shape.getPositionY());
	}
}
