// shape.cpp
#include "shape.h"

Shape::Shape()
{
	this->xVelocity = 0.0f;
	this->yVelocity = 0.0f;
	this->hasGravity = false;
	this->isPlayer = false;
	this->isProjectile = false;
}

Shape::~Shape()
{

}

bool Shape::getIsPlayer() const
{
	return isPlayer;
}

void Shape::setIsPlayer(bool isPlayer)
{
	this->isPlayer = isPlayer;
}

bool Shape::getGravity() const
{
	return hasGravity;
}

void Shape::setGravity(bool hasGravity)
{
	this->hasGravity = hasGravity;
}

float Shape::getXVelocity() const
{
	return xVelocity;
}

void Shape::setXVelocity(float xVelocity)
{
	this->xVelocity = xVelocity;
}

float Shape::getYVelocity() const
{
	return yVelocity;
}

void Shape::setYVelocity(float yVelocity)
{
	this->yVelocity = yVelocity;
}

float Shape::getPositionX() const
{
	return position.x;
}

float Shape::getPositionY() const
{
	return position.y;
}

void Shape::setPositionVector(int xPos, int yPos)
{
	this->position.x = xPos;
	this->position.y = yPos;
	this->setPosition(position);
}

void Shape::setImage(std::string imagePath)
{
	if (!this->image.loadFromFile(imagePath))
	{
		std::cout << "Failed to load image from " << imagePath << std::endl;
	}
}

void Shape::setSpriteTexture()
{
	if (!this->texture.loadFromImage(this->image))
	{
		std::cout << "Failed to create texture from image" << std::endl;
	}
	else
	{
		this->spriteSizeX = this->texture.getSize().x / 12.0;
		this->spriteSizeY = this->texture.getSize().y / 4.0;
		this->setTexture(texture);
	}
}


void Shape::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

void Shape::setSize(float x, float y)
{
	this->setScale(x, y);
}

void Shape::setViewBox(float x, float y)
{
	this->setTextureRect(sf::IntRect(x, y, this->spriteSizeX, this->spriteSizeY));
}

float Shape::getSpriteSizeX() const
{
	return this->spriteSizeX;
}

float Shape::getSpriteSizeY() const
{
	return this->spriteSizeY;
}

bool Shape::getIsProjectile() const
{
	return this->isProjectile;
}

void Shape::setIsProjectile(bool isProjectile)
{
	this->isProjectile = isProjectile;
}