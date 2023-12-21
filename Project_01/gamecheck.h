//gamecheck.h
#pragma once
#include <SFML/Graphics.hpp>
#include "shape.h"
#include "background.h"
#include "gameengine.h"
class GameCheck
{
private:
	bool WKeyPressed;
	bool SKeyPressed;
	bool AKeyPressed;
	bool DKeyPressed;
	bool FKeyPressed;
	std::string facingDirection;
	int counter;
	int backgroundState;
	std::string states[2];
	const int statesLength = sizeof(states)/sizeof(states[0]);
public:
	GameCheck();
	~GameCheck();
	void applyGameCheck(Shape& shape, Background& background, sf::RenderWindow& window, GameEngine* Engine, sf::Clock clock);
	void keyCheck();
	void playerCheck(Shape& shape, sf::RenderWindow& window, GameEngine* Engine, sf::Clock clock);
	void gameStateCheck(Shape& shape, Background& background);
	std::string gameState(int state);
	void setWKeyPressed(bool WKeyPressed);
	void setSKeyPressed(bool SKeyPressed);
	void setAKeyPressed(bool AKeyPressed);
	void setDKeyPressed(bool DKeyPressed);
	void setFKeyPressed(bool FKeyPressed);
	void setFacingDirection(std::string facingDirection);
	bool getWKeyPressed() const;
	bool getSKeyPressed() const;
	bool getAKeyPressed() const;
	bool getDKeyPressed() const;
	bool getFKeyPressed() const;
	std::string getFacingDirection() const;
	
};