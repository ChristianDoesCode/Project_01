// shape.h
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024
class Shape : sf::Sprite
{
private:
	bool hasGravity;
	float xVelocity;
	float yVelocity;
	bool isPlayer;
	bool isProjectile;
	bool isDeleted;
	float spriteSizeX;
	float spriteSizeY;
	int level;
	sf::Vector2f position;
	sf::Image image;
	sf::Texture texture;

public:
	Shape();
	~Shape();

	bool getIsPlayer() const;
	void setIsPlayer(bool isPlayer);
	bool getGravity() const;
	void setGravity(bool hasGravity);
	float getXVelocity() const;
	void setXVelocity(float xVelocity);
	float getYVelocity() const;
	void setYVelocity(float yVelocity);
	float getPositionX() const;
	float getPositionY() const;
	float getSpriteSizeX() const;
	float getSpriteSizeY() const;
	void setPositionVector(int xPos, int yPos);
	void setImage(std::string imagePath);
	void setSpriteTexture();
	void draw(sf::RenderWindow& window);
	void setSize(float x, float y);
	void setViewBox(float x, float y);
	bool getIsProjectile() const;
	void setIsProjectile(bool isProjectile);
	bool getIsDeleted() const;
	void setIsDeleted(bool isDeleted);
};