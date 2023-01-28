#include "Circle.h"

//Cons / Decons
Circle::Circle() {
	//init vars
	this->radius = 30;
	this->pos.x = 0.f, this->pos.y = 0.f;
	this->v.x = 0.f, v.y = 0.f;
	this->a.x = 20.f, a.y = 0.f;

	//init cir
	this->cir.setPosition(pos.x, pos.y);
	this->cir.setRadius(radius);
	this->cir.setFillColor(sf::Color::Cyan);
	//this->cir.setOutlineColor(sf::Color::Green);
	//this->cir.setOutlineThickness(1.f);
}

Circle::~Circle() {

}

//access
sf::CircleShape Circle::body() {
	return this->cir;
}

//motion
void Circle::iterate(float dt) {
	/*
		temporary using Eular's mathod,
		will change into Runge Kutta or something like that
	*/
	pos += v * dt;
	v += a * dt;
}

void Circle::move() {
	this->cir.setPosition(pos.x, pos.y);
}