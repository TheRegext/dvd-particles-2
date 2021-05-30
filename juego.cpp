#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particle.h"

float randomVelocity(float velocity)
{
	return std::max<float>((std::rand() % 100 + 1) / 100.0f * velocity, .5f);
}

int main()
{
	sf::Clock clock;
	srand(std::time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);

	sf::Texture texture;

	if (!texture.loadFromFile("images/logo2.png"))
	{
		// error...
	}

	sf::Vector2f vel(100,100);
	float velocity = 1000.0f;

	sf::Sprite sprite;
	sprite.setTexture(texture);

	std::vector <Particle> particle;

	for (int i = 0; i < 500; i++) {
		particle.push_back(Particle());
	}


	for (Particle& p : particle) {
		p.setObserver(&sprite);
	}

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sprite.move(vel * elapsed.asSeconds());

		// Logica 
		if ((sprite.getGlobalBounds().left + sprite.getGlobalBounds().width) > window.getView().getSize().x) {
			sprite.setColor(sf::Color::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255));
			vel.x = -randomVelocity(velocity);

			for (Particle& p : particle) {
					p.reset();
			}
		}

		if (sprite.getGlobalBounds().left < 0.0f) {
			sprite.setColor(sf::Color::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255));
			vel.x = randomVelocity(velocity);
			for (Particle& p : particle) {
					p.reset();
			}
		}

		if ((sprite.getGlobalBounds().top + sprite.getGlobalBounds().height) > window.getView().getSize().y) {
			sprite.setColor(sf::Color::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255));
			vel.y = -randomVelocity(velocity);
			for (Particle& p : particle) {
					p.reset();
			}
		}

		if (sprite.getGlobalBounds().top < 0.0f) {
			sprite.setColor(sf::Color::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256, 255));
			vel.y = randomVelocity(velocity);
			for (Particle& p : particle) {
					p.reset();
			}
		}

		// particle

		for (Particle& p : particle) {
			p.update(elapsed.asSeconds());

			// Piso
			if (p.getPosition().y > window.getView().getSize().y)
			{
				p.setPosition(sf::Vector2f(p.getPosition().x, window.getView().getSize().y));
				p.bounce();
			}

			// Pared
			if (p.getPosition().x > window.getView().getSize().x)
			{
				p.setPosition(sf::Vector2f(window.getView().getSize().x, p.getPosition().y));
				p.bounceX();
			}

			if (p.getPosition().x < 0)
			{
				p.setPosition(sf::Vector2f(0, p.getPosition().y));
				p.bounceX();
			}
		}
		/*
		for (int i = 0; i < particle.size(); i++) {
			for (int p = i+1; p < particle.size()-1; p++) {

				if (particle[i].isCollision(particle[p])) {
					particle[i].repel(1);
					particle[p].repel(-1);
					break;
				}
			}
		}
		*/
		/*
		sprite.setPosition(400, 300);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			for (Particle& p : particle) {
				p.reset();
			}
		}
		*/
		
		window.clear();

		for (Particle& p : particle) {
			p.draw(window);
		}


		
		window.draw(sprite);
		

		window.display();

	}

	return 0;
}