#include "Game.h"

Game::Game(int screenWidth, int screenHeight) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

void Game::handleEvents() {
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::run() {
	window.create(sf::VideoMode(screenWidth, screenHeight), "Arkanoid");
	while (window.isOpen()) {
		handleEvents();
		window.clear();

		window.display();
	}
}