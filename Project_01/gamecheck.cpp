//gamecheck.cpp
#include "gamecheck.h"

GameCheck::GameCheck()
{

}

GameCheck::~GameCheck()
{

}

void GameCheck::setSpaceKeyPressed(bool spaceKeyPressed)
{
	this->WKeyPressed = spaceKeyPressed;
}

bool GameCheck::getSpaceKeyPressed() const
{
	return WKeyPressed;
}

void GameCheck::applyGameCheck(Shape& shape)
{
	this->keyCheck();
	this->playerCheck(shape);
}

void GameCheck::keyCheck()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->WKeyPressed = true;
	}
	else
	{
		this->WKeyPressed = false;
	}
}

void GameCheck::playerCheck(Shape& shape)
{
	if (shape.getIsPlayer() == false)
	{
		return;
	}
	else if (shape.getIsPlayer() == true)
	{
		if (this->WKeyPressed == true)
		{
			shape.setYVelocity(-10.0f);
		}
		else
		{
			shape.setYVelocity(0.0f);
		}
	}
}
