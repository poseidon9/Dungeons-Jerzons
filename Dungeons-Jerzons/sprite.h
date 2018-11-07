#ifndef SPRITE_H

#define SPRITE_H
#include <SDL.h>
#include <string>

class Graphics;

/*	Sprite class
	holds all information for indivual sprites
*/

class Sprite
{
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);

	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);

	/*
		SHOULD BE PRIVATE REMEMBER TO DELETE THIS!
	*/
	float _x, _y;
	/*
		PLS NO FORGETERINO!
	*/

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

private:
	//float _x, _y;
};

#endif