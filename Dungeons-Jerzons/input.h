#ifndef INPUT_H

#define INPUT_H
#include <SDL.h>
#include <map>

class Input
{
public:
	void beginNewFrame();
	void keyUpEvent(const SDL_Event& event);
	void keyDownEvent(const SDL_Event& event);
	void keyLeftEvent(const SDL_Event& event);
	void keyRightEvent(const SDL_Event& event);
private:
	std::map<SDL_Scancode, bool> _heldKeys;
	std::map<SDL_Scancode, bool> _pressedKeys;
	std::map<SDL_Scancode, bool> _releasedKeys;
};

#endif