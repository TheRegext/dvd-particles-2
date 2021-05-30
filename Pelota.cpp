#include "Pelota.h"

Pelota::Pelota()
	:_shape(10)
{
	_shape.setFillColor(sf::Color::Green);
}

sf::CircleShape Pelota::getShape()
{
	return _shape;
}

void Pelota::mover()
{
	
}
