#include "graphics.h"
#include <SDL.h>

/*
	Graphics Class
	Holds all information dealing with graphics for the game.
*/

Graphics::Graphics()
{
	SDL_CreateWindowAndRenderer(640, 480, 0, &this._window, &this._renderer);
	SDL_SetWindowTitle(this._window, "DungeonsDragons");
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(this._window);
}

