// shape.h
#pragma once
#include <SFML/Graphics.hpp>

class Shape
{
private:
	bool hasGravity;

public:
	Shape();
	~Shape();

	bool getGravity() const;
	void setGravity(bool hasGravity);


};