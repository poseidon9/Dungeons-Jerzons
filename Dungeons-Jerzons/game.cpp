#include <SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

/*  Game Class
	This class holds all information for our main game loop.
*/
namespace
{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game()
{

}

void Game::gameLoop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	this->_player = Sprite(graphics, "Imagenes/Sprites/walking/thebravewalk1.png", 0, 0, 64, 64, 50, 50);

	int LAST_UPDATE_TIME = SDL_GetTicks();
	//Start the game loop
	while (true)
	{
		input.beginNewFrame();

		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0)
				{
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				input.keyUpEvent(event);
			}

			if (event.type == SDL_QUIT)
			{
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return;
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		//std::min
		this->update(std::_Min_value(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics)
{
	graphics.clear();
	this->_player.draw(graphics, 100, 100);

	graphics.flip();
}

void Game::update(float elapsedTime)
{

}

