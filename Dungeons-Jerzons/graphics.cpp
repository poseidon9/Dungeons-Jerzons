#include <SDL.h>
#include "graphics.h"

/* Graphics class
	Holds all information 
*/

Graphics::Graphics()
{	
 	SDL_CreateWindowAndRenderer(640, 480, 0,  &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Dungeons&Jerzons");
}


Graphics::~Graphics()
{
	SDL_DestroyWindow(this->_window);
}
