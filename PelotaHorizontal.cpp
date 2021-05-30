#include "PelotaHorizontal.h"
PelotaHorizontal::PelotaHorizontal()
{
	_velocity = { 1, 0 };
}
void PelotaHorizontal::mover()
{
	_shape.move(_velocity.x, 0);

	if (_shape.getPosition().x > 400 - _shape.getRadius() * 2 || _shape.getPosition().x < 0) {
		_velocity.x *= -1;
	}

}