//gamecheck.cpp
#include "gamecheck.h"


GameCheck::GameCheck()
{
	this->WKeyPressed = false;
	this->SKeyPressed = false;
	this->AKeyPressed = false;
	this->DKeyPressed = false;
	this->FKeyPressed = false;
	this->facingDirection = "None";
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

void GameCheck::setFKeyPressed(bool FKeyPressed)
{
	this->FKeyPressed = FKeyPressed;
}

void GameCheck::setFacingDirection(std::string facingDirection)
{
	this->facingDirection = facingDirection;
}

bool GameCheck::getWKeyPressed() const
{
	return this->WKeyPressed;
}

bool GameCheck::getSKeyPressed() const
{
	return this->SKeyPressed;
}

bool GameCheck::getAKeyPressed() const
{
	return this->AKeyPressed;
}

bool GameCheck::getDKeyPressed() const
{
	return this->DKeyPressed;
}

bool GameCheck::getFKeyPressed() const
{
	return this->FKeyPressed;
}

std::string GameCheck::getFacingDirection() const
{
	return this->facingDirection;
}

void GameCheck::applyGameCheck(Shape& shape, Background& background, sf::RenderWindow& window, GameEngine* Engine, sf::Clock clock)
{
	this->keyCheck();
	this->playerCheck(shape, window, Engine, clock);
	this->gameStateCheck(shape, background);
}

void GameCheck::keyCheck()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->WKeyPressed = true;
		this->facingDirection = "N";
	}
	else
	{
		this->WKeyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->SKeyPressed = true;
		this->facingDirection = "S";
	}
	else
	{
		this->SKeyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->AKeyPressed = true;
		this->facingDirection = "W";
	}
	else
	{
		this->AKeyPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->DKeyPressed = true;
		this->facingDirection = "E";
	}
	else
	{
		this->DKeyPressed = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		this->FKeyPressed = true;
	}
	else
	{
		this->FKeyPressed = false;

	}
}

void GameCheck::playerCheck(Shape& shape, sf::RenderWindow& window, GameEngine* Engine, sf::Clock clock)
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
		if (this->FKeyPressed == true)
		{
			if (facingDirection == "N")
			{
				std::cout << "this ran!" << std::endl;
				Shape bullet;
				bullet.setImage("can.png");
				bullet.setSpriteTexture();
				bullet.setSize(0.1f, 0.1f);
				bullet.setPositionVector(100 + 100, 100 + 50);
				bullet.setYVelocity(-5.0f);
				bullet.setIsProjectile(true);
				Engine->applyGameEngine(bullet, SCREEN_WIDTH, SCREEN_HEIGHT, clock);
				bullet.draw(window);
			}
			else if (facingDirection == "S")
			{
				std::cout << "this ran!" << std::endl;
				Shape bullet;
				bullet.setImage("can.png");
				bullet.setSpriteTexture();
				bullet.setSize(0.1f, 0.1f);
				bullet.setPositionVector(100 + 100, 100 + 50);
				bullet.setYVelocity(5.0f);
				bullet.setIsProjectile(true);
				Engine->applyGameEngine(bullet, SCREEN_WIDTH, SCREEN_HEIGHT, clock);
				bullet.draw(window);
			}
			else if (facingDirection == "E")
			{
				std::cout << "this ran!" << std::endl;
				Shape bullet;
				bullet.setImage("can.png");
				bullet.setSpriteTexture();
				bullet.setSize(0.1f, 0.1f);
				bullet.setPositionVector(100 + 100, 100 + 50);
				bullet.setXVelocity(5.0f);
				bullet.setIsProjectile(true);
				Engine->applyGameEngine(bullet, SCREEN_WIDTH, SCREEN_HEIGHT, clock);
				bullet.draw(window);
			}
			else if (facingDirection == "W")
			{
				std::cout << "this ran!" << std::endl;
				Shape bullet;
				bullet.setImage("can.png");
				bullet.setSpriteTexture();
				bullet.setSize(0.1f, 0.1f);
				bullet.setPositionVector(100 + 100, 100 + 50);
				bullet.setXVelocity(-5.0f);
				bullet.setIsProjectile(true);
				Engine->applyGameEngine(bullet, SCREEN_WIDTH, SCREEN_HEIGHT, clock);
				bullet.draw(window);
			}
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
