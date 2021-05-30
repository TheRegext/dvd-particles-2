#pragma once
#include <SFML/Graphics.hpp>
class Particle
{
private :
	sf::Sprite *_ob;
	sf::CircleShape _particle;
	float _scale;
	float _velocity;
	float _gravity;
	float _force;
	float _moveForce;
	float _friction;
	float _rotateVelocity;

	bool _isLive;

public:
	Particle();
	void setObserver(sf::Sprite* ob);
	void update(float );

	void reset();
	void draw(sf::RenderWindow &window);

	void setPosition(sf::Vector2f pos);
	const sf::Vector2f& getPosition();

	void bounce();
	void bounceX();


	bool isCollision(const Particle& p);
	void repel(float factor);
};

