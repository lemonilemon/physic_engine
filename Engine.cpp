#include "Engine.h"
#include <string>
#include <iostream>

//Pricate finctions
void Engine::init_vars() {
	this->window = nullptr;

	this->framerate = 60;
	this->dt = float(1) / framerate;
	this->timer = 0;

	this->pause = false;
}

void Engine::init_window() {
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	this->window = new sf::RenderWindow(this->videoMode, "Test", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(framerate);
}

void Engine::init_objs() {
	this->rec.setPosition(300.f, 400.f);
	this->rec.setSize(sf::Vector2f(100.f, 100.f));
	//this->rec.setScale(sf::Vector2f(0.5f, 0.5f));
	this->rec.setFillColor(sf::Color::Cyan);
	this->rec.setOutlineColor(sf::Color::Green);
	this->rec.setOutlineThickness(1.f);
}

void Engine::init_texts() {
	if (!this->font.loadFromFile("./fonts/RobotoMono-Regular.ttf")) {
		printf("load font failed\n");
		system("pause");
	}

	this->cir_pos.setFont(font);
	this->cir_pos.setCharacterSize(20);
	cir_pos.setFillColor(sf::Color::White);
	cir_pos.setPosition(0.f, 500.f);
}

//Constructors / Destructors
Engine::Engine() {
	this->init_vars();
	this->init_window();
	this->init_objs();
	this->init_texts();
}

Engine::~Engine() {
	delete this->window;
}

//Accessors
const bool Engine::running() const {
	return this->window->isOpen();
}

//Funcitons
void Engine::poll_events() {
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Engine::update() {
	this->poll_events();

	if (!this->pause) {
		cir.iterate(dt);
		cir.move();

		timer += dt;

		if (timer >= 5)	pause = true;
	}
}

void Engine::render() {
	this->window->clear();

	//draw object
	this->window->draw(cir.body());

	//draw text
	std::string s = "pos = (" + std::to_string(cir.pos.x) + ", " + std::to_string(cir.pos.y) + ")";
	s += ("\ndt = " + std::to_string(dt) + ", time = " + std::to_string(timer));

	float theo = 1.f / 2.f * 20.f * timer * timer;	// theoreical delta x 
	s += ("\ncaculated x = " + std::to_string(theo) + ", deviation = " + std::to_string(theo - cir.pos.x));

	cir_pos.setString(s);

	this->window->draw(cir_pos);

	this->window->display();
}
