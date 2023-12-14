// shape.cpp
#include "shape.h"

Shape::Shape()
{

}

Shape::~Shape()
{

}

bool Shape::getGravity() const
{
	return hasGravity;
}

void Shape::setGravity(bool hasGravity)
{
	this->hasGravity = hasGravity;
}

