// shape.h
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Shape : sf::Sprite
{
private:
	bool hasGravity;
	float xVelocity;
	float yVelocity;
	sf::Vector2f position;
	sf::Image image;
	sf::Texture texture;

public:
	Shape();
	~Shape();

	bool getGravity() const;
	void setGravity(bool hasGravity);
	float getXVelocity() const;
	void setXVelocity(float xVelocity);
	float getYVelocity() const;
	void setYVelocity(float yVelocity);
	float getPositionX() const;
	float getPositionY() const;
	void setPositionVector(int xPos, int yPos);
	void setImage(std::string imagePath);
	void setSpriteTexture();
	void draw(sf::RenderWindow& window);
};