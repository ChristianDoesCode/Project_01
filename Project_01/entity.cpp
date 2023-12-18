//entity.cpp
#include "entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

bool Entity::getIsPlayer() const
{
	return isPlayer;
}

void Entity::setIsPlayer(bool isPlayer)
{
	this->isPlayer = isPlayer;
}