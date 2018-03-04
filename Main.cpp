#include "SDL/include/SDL.h"

#pragma comment (lib, "SDL/x86/SDL2.lib")
#pragma comment (lib, "SDL/x86/SDL2main.lib")

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	int a = 1;
	SDL_Window* window;
	SDL_Rect rect;
	SDL_Renderer* renderer;
	rect.w = 50;
	rect.h = 30;
	//SDL_Event event;
	window = SDL_CreateWindow(
		"Awesomw Game",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		500,
		500,
		0
	);
	int x = 250;
	int y = 250;

	renderer = SDL_CreateRenderer(window, -1, 0);
	while (a == 1) {
		rect.x = x;
		rect.y = y;
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);

		//SDL_Delay(10);
	}
		SDL_Quit();
		return 0;
}