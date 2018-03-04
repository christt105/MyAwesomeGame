#include "SDL/include/SDL.h"

#pragma comment (lib, "SDL/x86/SDL2.lib")
#pragma comment (lib, "SDL/x86/SDL2main.lib")

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	
	
	SDL_Quit();
	return 0;
}