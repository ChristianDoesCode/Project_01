//gamecheck.h
#pragma once
#include <SFML/Graphics.hpp>
#include "shape.h"
class GameCheck
{
private:
	bool WKeyPressed;
public:
	GameCheck();
	~GameCheck();
	void applyGameCheck(Shape& shape);
	void keyCheck();
	void playerCheck(Shape& shape);
	void setSpaceKeyPressed(bool spaceKeyPressed);
	bool getSpaceKeyPressed() const;
	
};