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

	this->_player = AnimatedSprite(graphics, "Imagenes/Sprites/geruzon.png", 0, 0, 49, 49, 100, 100, 100);
	this->_player.setupAnimations();
	this->_player.playAnimation("RunLeft");

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

		/*	DELETE THIS CHUNK OF CODE
			
		*/
		if (input.isKeyHeld(SDL_SCANCODE_A))
		{
			_player._x -= 1;
		}
		if (input.isKeyHeld(SDL_SCANCODE_W))
		{
			_player._y -= 1;
		}
		if (input.isKeyHeld(SDL_SCANCODE_D))
		{
			_player._x += 1;
		}
		if (input.isKeyHeld(SDL_SCANCODE_S))
		{
			_player._y += 1;
		}
		/*
			DID U DELETE IT?
		*/

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
	this->_player.draw(graphics, this->_player._x, this->_player._y); //100, 100

	graphics.flip();
}

void Game::update(float elapsedTime)
{
	this->_player.update(elapsedTime);
}

