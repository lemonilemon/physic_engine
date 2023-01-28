#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


class Circle {
private:
	sf::CircleShape cir;
	float radius;

public:
	Circle();
	~Circle();

	sf::Vector2f pos, v, a;

	//access
	sf::CircleShape body();

	//motion
	void iterate(float dt);
	void move();
};

#endif // CIRCLE_H