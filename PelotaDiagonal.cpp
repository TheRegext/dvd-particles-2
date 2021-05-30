#include "PelotaDiagonal.h"

PelotaDiagonal::PelotaDiagonal()
{
	_velocity = { 1, 1 };
}

PelotaDiagonal::PelotaDiagonal(float vel) {
	_velocity = { vel,vel };
}

void PelotaDiagonal::mover()
{
	_shape.move(_velocity.x, _velocity.y);

	if (_shape.getPosition().y > 400 - _shape.getRadius() * 2 || _shape.getPosition().y < 0) {
		_velocity.y *= -1;
	}
	if (_shape.getPosition().x > 400 - _shape.getRadius() * 2 || _shape.getPosition().x < 0) {
		_velocity.x *= -1;
	}
}
