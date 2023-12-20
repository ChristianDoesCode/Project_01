//gamecheck.h
#pragma once
#include <SFML/Graphics.hpp>
#include "shape.h"
#include "background.h"
class GameCheck
{
private:
	bool WKeyPressed;
	bool SKeyPressed;
	bool AKeyPressed;
	bool DKeyPressed;
	int counter;
	int backgroundState;
	std::string states[2];
	const int statesLength = sizeof(states)/sizeof(states[0]);
public:
	GameCheck();
	~GameCheck();
	void applyGameCheck(Shape& shape, Background& background);
	void keyCheck();
	void playerCheck(Shape& shape);
	void gameStateCheck(Shape& shape, Background& background);
	std::string gameState(int state);
	void setWKeyPressed(bool WKeyPressed);
	void setSKeyPressed(bool WKeyPressed);
	void setAKeyPressed(bool WKeyPressed);
	void setDKeyPressed(bool WKeyPressed);
	bool getWKeyPressed() const;
	bool getSKeyPressed() const;
	bool getAKeyPressed() const;
	bool getDKeyPressed() const;
	
};