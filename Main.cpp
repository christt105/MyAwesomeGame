#include "SDL/include/SDL.h"

#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	int a = 1;
	SDL_Window* window;
	SDL_Rect rect;
	SDL_Rect shot;
	SDL_Renderer* renderer;
	rect.w = 50;
	rect.h = 30;
	shot.w = 40;
	shot.h = 5;
	SDL_Event event;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	window = SDL_CreateWindow(
		"Awesomw Game",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		500,
		500,
		0
	);
	int x=250;
	int y=250;
	renderer = SDL_CreateRenderer(window, -1, 0);
	while(a==1) {
		rect.x = x;
		rect.y = y;
		
		if (SDL_PollEvent(&event) != 0) {
			if (event.window.event == SDL_WINDOWEVENT_CLOSE || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				a = 0;
				SDL_DestroyWindow(window);
			}
			else{
				if (state[SDL_SCANCODE_DOWN])
					y = y + 5;
				if (state[SDL_SCANCODE_UP])
					y = y - 5;
				if (state[SDL_SCANCODE_RIGHT])
					x = x + 5;
				if (state[SDL_SCANCODE_LEFT])
					x = x - 5;
				if (state[SDL_SCANCODE_SPACE]) {
					shot.x = rect.x + 25;
					shot.y = rect.y + 15;
				}	
			}
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &shot);
		shot.x++;
		SDL_RenderPresent(renderer);
	}
	SDL_Quit();
	return 0;
}