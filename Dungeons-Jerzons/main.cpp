#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char * argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf_s("SDL initialization failed. SDL Error: " );
	}
	else
	{
		cout << "SDL initialization succeeded!";
	}

	cin.get();
	return 0;
}