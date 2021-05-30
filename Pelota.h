#pragma once
#include <SFML/Graphics.hpp>
class Pelota
{
protected:
	sf::CircleShape _shape;
	sf::Vector2f _velocity;

public:
	Pelota();
	virtual void mover();
	sf::CircleShape getShape();
	
};

