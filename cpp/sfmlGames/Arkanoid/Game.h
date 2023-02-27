#pragma once

#include <SFML/Graphics.hpp>

class Game
{
	sf::Event event;
	sf::RenderWindow window;
	int screenWidth;
	int screenHeight;
	void handleEvents();
public:
	Game() = delete;
	Game(int, int);
	void run();
};

