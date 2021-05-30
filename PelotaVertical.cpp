#include "PelotaVertical.h"

PelotaVertical::PelotaVertical()
{
	_velocity = { 0, 1 };
}

void PelotaVertical::mover()
{
	_shape.move(0, _velocity.y);

	if (_shape.getPosition().y > 400 - _shape.getRadius() * 2 || _shape.getPosition().y < 0) {
		_velocity.y *= -1;
	}
}
