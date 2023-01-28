#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>


#include "Engine.h"
#include "Circle.h"

int main()
{
	//Init engine
	Engine engine;

	//Loop
	while(engine.running()){
		//Update
		engine.update();
		//Render
		engine.render();
	}
	

	//End
    return 0;
}
