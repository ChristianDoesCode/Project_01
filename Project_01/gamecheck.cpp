//gamecheck.cpp
#include "gamecheck.h"


GameCheck::GameCheck()
{
	this->WKeyPressed = false;
	this->SKeyPressed = false;
	this->AKeyPressed = false;
	this->DKeyPressed = false;
	this->counter = 0;
	this->backgroundState = 0;
	this->states[0] = "background.jpg";
	this->states[1] = "test.jpg";

}

GameCheck::~GameCheck()
{

}

void GameCheck::setWKeyPressed(bool WKeyPressed)
{
	this->WKeyPressed = WKeyPressed;
}

void GameCheck::setSKeyPressed(bool SKeyPressed)
{
	this->SKeyPressed = SKeyPressed;
}

void GameCheck::setAKeyPressed(bool AKeyPressed)
{
	this->AKeyPressed = AKeyPressed;
}

void GameCheck::setDKeyPressed(bool DKeyPressed)
{
	this->DKeyPressed = DKeyPressed;
}

bool GameCheck::getWKeyPressed() const
{
	return WKeyPressed;
}

bool GameCheck::getSKeyPressed() const
{
	return SKeyPressed;
}

bool GameCheck::getAKeyPressed() const
{
	return AKeyPressed;
}

bool GameCheck::getDKeyPressed() const
{
	return DKeyPressed;
}

void GameCheck::applyGameCheck(Shape& shape, Background& background)
{
	this->keyCheck();
	this->playerCheck(shape);
	this->gameStateCheck(shape, background);
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->SKeyPressed = true;
	}
	else
	{
		this->SKeyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->AKeyPressed = true;
	}
	else
	{
		this->AKeyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->DKeyPressed = true;
	}
	else
	{
		this->DKeyPressed = false;
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
			if (counter > 11)
			{
				counter = 0;
				shape.setViewBox(counter * shape.getSpriteSizeX(), shape.getSpriteSizeY() * 3.0);
			}
			else
			{
				shape.setViewBox(counter * shape.getSpriteSizeX(), shape.getSpriteSizeY() * 3.0);
				counter++;
			}

			shape.setYVelocity(-10.0f);
		}

		if (this->SKeyPressed == true)
		{
			if (counter > 11)
			{
				counter = 0;
				shape.setViewBox(counter * shape.getSpriteSizeX(), shape.getSpriteSizeY() * 0.0);
			}
			else
			{
				shape.setViewBox(counter * shape.getSpriteSizeX(), shape.getSpriteSizeY() * 0.0);
				counter++;
			}

			shape.setYVelocity(10.0f);
		}

		if (this->WKeyPressed == false && this->SKeyPressed == false)
		{
			shape.setYVelocity(0.0f);
		}

		if (this->AKeyPressed == true)
		{
			if (counter > 11)
			{
				counter = 0;
				shape.setViewBox(counter * shape.getSpriteSizeX(), shape.getSpriteSizeY() * 1.0);
			}
			else
			{
				shape.setViewBox(counter * shape.getSpriteSizeX(), shape.getSpriteSizeY() * 1.0);
				counter++;
			}

			shape.setXVelocity(-10.0f);
		}
	
		if (this->DKeyPressed == true)
		{
			if (counter > 11)
			{
				counter = 0;
				shape.setViewBox(counter * shape.getSpriteSizeX(), shape.getSpriteSizeY() * 2.0);
			}
			else
			{
				shape.setViewBox(counter * shape.getSpriteSizeX(), shape.getSpriteSizeY() * 2.0);
				counter++;
			}

			shape.setXVelocity(10.0f);
		}
		
		if (this->AKeyPressed == false && this->DKeyPressed == false)
		{
			shape.setXVelocity(0.0f);
		}
	}
}

void GameCheck::gameStateCheck(Shape& shape, Background& background)
{
	if (shape.getIsPlayer() == false)
	{
		return;
	}
	else if (shape.getIsPlayer() == true)
	{
		if (shape.getPositionX() + 1 + 100 >= SCREEN_WIDTH && !(shape.getPositionY() + 1 + 100 >= SCREEN_HEIGHT) && !(shape.getPositionY() - 1 <= 0))
		{
			//Make sure backgroundState does not keep increasing if there is no background to switch too
			if (this->backgroundState + 1 < this->statesLength)
			{
				this->backgroundState++;
				shape.setPositionVector(2, shape.getPositionY());
			}
			//Switch state if there is one to switch too
			if (this->backgroundState >= 0 && this->backgroundState < this->statesLength)
			{
				background.setBackground(this->gameState(this->backgroundState));
			}
		}
		if (shape.getPositionX() - 1 <= 0 && !(shape.getPositionY() + 1 + 100 >= SCREEN_HEIGHT) && !(shape.getPositionY() - 1 <= 0))
		{
			//Make sure backgroundState does not keep decreasing if there is no background to switch too
			if (this->backgroundState - 1 >= 0)
			{
				this->backgroundState--;
				//teleport to the opposite edge
				shape.setPositionVector(SCREEN_WIDTH - 100 - 2, shape.getPositionY());
			}
			//Switch state if there is one to switch too
			if (this->backgroundState >= 0 && this->backgroundState < this->statesLength)
			{
				background.setBackground(this->gameState(this->backgroundState));
			}
		}
	}
}
//takes in a state number then outputs the file path as a string for that state (No Error Handling)
std::string GameCheck::gameState(int state)
{
	return this->states[state];
}
