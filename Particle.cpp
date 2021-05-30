#include "Particle.h"
#include <iostream>
float minmax(float min, float max, float value) {
	return value < min ? min : (value > max ? max : value);
}


Particle::Particle()
	: _ob(nullptr), _scale(0), _particle(10), _velocity(0.05), _gravity(.2), _force(0), _moveForce(.5), _friction(.1), _rotateVelocity(1), _isLive(false)
{
	_particle.setOrigin(_particle.getRadius() / 2, _particle.getRadius() / 2);
	_velocity = (1 / (60.0f * (std::rand() % 100) / 100));
}

void Particle::setPosition(sf::Vector2f pos)
{
	_particle.setPosition(pos);
}

const sf::Vector2f& Particle::getPosition()
{
	return _particle.getPosition();
}

void Particle::bounce()
{
	_force = (_force > 10 ? 10 : _force) * -.5 ;
}

void Particle::bounceX()
{
	_moveForce *= -1;
}

bool Particle::isCollision(const Particle& p)
{
	return _particle.getGlobalBounds().intersects(p._particle.getGlobalBounds());
}

void Particle::repel(float factor)
{
	_moveForce *= factor;
}

void Particle::reset()
{

	if (!_isLive) {
		_particle.setPosition(_ob->getPosition());
		//_particle.move(_ob->getGlobalBounds().width / 4 + _ob->getGlobalBounds().width / 2 * (std::rand() % 100 + 1) / 100.f, _ob->getGlobalBounds().height / 4 + _ob->getGlobalBounds().height / 2 * (std::rand() % 100 + 1) / 100.f);
		//_particle.move(_ob->getGlobalBounds().width * (std::rand() % 100 + 1) / 100.f, _ob->getGlobalBounds().height  * (std::rand() % 100 + 1) / 100.f);

		_particle.move(_ob->getGlobalBounds().width / 2, _ob->getGlobalBounds().height / 2);
		_scale = 2 * (std::rand() % 100 + 1) / 100.0f;

		_velocity = (1 / (60.0f * (std::rand() % 200) / 100));

		//_particle.setFillColor(sf::Color::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255));	}

		sf::Color color = _ob->getColor();

		color.a = 255 * (std::rand() % 100 + 1) / 100.0f;
		color.r *= 255 * (std::rand() % 100 + 1) / 100.0f;
		color.g *= 255 * (std::rand() % 100 + 1) / 100.0f;
		color.b *= 255 * (std::rand() % 100 + 1) / 100.0f;


		_particle.setFillColor(color);
		_force = -5 * (std::rand() % 100 + 1) / 100.0f;


		_moveForce = 10 * (std::rand() % 100 + 1) / 100.0f * (std::rand()%2 ? -1 : 1);

		_friction = .98;

		_rotateVelocity = (std::rand() % 100 + 1) / 100.0f * (std::rand() % 2 ? -1 : 1);
		_isLive = true;

	}
}

void Particle::update(float delta)
{
	if (_scale >= 0) {
		_particle.setScale(_scale, _scale*.2);
		_particle.setRotation(360 * ((_scale * 10 * _rotateVelocity)/2));

		sf::Color c = _particle.getFillColor();
	
		c.a = 255 * (_scale / (2));

		_particle.setFillColor(c);
		_scale -= _velocity;

		// gravedad
		_force += _gravity;
		_moveForce *= _friction;
		
		_particle.move(_moveForce, _force);
		
	}
	else {
		_isLive = false;
	}
}

void Particle::draw(sf::RenderWindow& window)
{
	if (_isLive) {
		sf::BlendMode masksCombining = sf::BlendAdd;
		masksCombining.colorEquation = sf::BlendMode::Add;
		
		window.draw(_particle, masksCombining);
	}
}

void Particle::setObserver(sf::Sprite* ob)
{
	_ob = ob;
}
