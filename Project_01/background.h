#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 1024.0
#define SCREEN_HEIGHT 1024.0

class Background: sf::Sprite
{
private:
	sf::Texture backgroundTexture;
	float xScale;
	float yScale;
public:
	Background(std::string imagePath);
	~Background();
	void draw(sf::RenderWindow& window);
	void setBackground(std::string imagePath);
};
