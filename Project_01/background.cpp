#include "background.h"

Background::Background(std::string imagePath)
{
	this->backgroundTexture.loadFromFile(imagePath);
	this->xScale = SCREEN_WIDTH / this->backgroundTexture.getSize().x;
	this->yScale = SCREEN_HEIGHT / this->backgroundTexture.getSize().y;
	this->setTexture(this->backgroundTexture);
	this->setScale(this->xScale, this->yScale);
}

Background::~Background()
{

}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

void Background::setBackground(std::string imagePath)
{
	this->backgroundTexture.loadFromFile(imagePath);
	this->xScale = SCREEN_WIDTH / this->backgroundTexture.getSize().x;
	this->yScale = SCREEN_HEIGHT / this->backgroundTexture.getSize().y;
	this->setTexture(this->backgroundTexture);
	this->setScale(this->xScale, this->yScale);
}