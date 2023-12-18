//entity.h
#pragma once
#include "shape.h"

class Entity : public Shape
{
private:
	bool isPlayer;
public:
	Entity();
	~Entity();
	bool getIsPlayer() const;
	void setIsPlayer(bool isPlayer);
};