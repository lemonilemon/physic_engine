#include "libs/engine.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello world!");
	window.setPosition(sf::Vector2i(100, 100));
	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
				break;
			}
			window.display();
		}
	}
    return 0;
}
