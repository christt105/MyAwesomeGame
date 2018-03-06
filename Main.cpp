#include "SDL/include/SDL.h"
#include "SDL/include/SDL_image.h"

#pragma comment (lib, "SDL/libx86/SDL2.lib")
#pragma comment (lib, "SDL/libx86/SDL2main.lib")
#pragma comment (lib, "SDL/SDL_Image/libx86/SDL2_image.lib")

int main(int argc, char* argv[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	int a = 1;
	SDL_Window* window;
	SDL_Rect rect;
	SDL_Rect shot;
	SDL_Renderer* renderer;
	SDL_Surface* goku;
	goku = IMG_Load("goku.png");
	SDL_Surface* background;
	background = IMG_Load("minecraft.png");
	SDL_Texture* back_tx;
	SDL_Surface* shoot;
	shoot = IMG_Load("hellokitty.png");
	
	rect.w = 793/5;
	rect.h = 1007/5;
	rect.x = 50;
	rect.y = 50;
	shot.w = 50;
	shot.h = 50;
	SDL_Event event;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	window = SDL_CreateWindow(
		"Awesomw Game",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280,
		720,
		SDL_WINDOW_OPENGL
	);
	int x=100;
	int y=100;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Texture* goku_tx = SDL_CreateTextureFromSurface(renderer, goku);
	back_tx = SDL_CreateTextureFromSurface(renderer, background);
	SDL_Texture* shoot_tx = SDL_CreateTextureFromSurface(renderer, shoot);
	bool movUp = false;
	bool movDown = false;
	bool movLeft = false;
	bool movRight = false;

	while(a==1) {
		//rect.x = x;
		//rect.y = y;
		
		if (SDL_PollEvent(&event) != 0) {
			if (event.window.event == SDL_WINDOWEVENT_CLOSE || event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				a = 0;
				SDL_DestroyWindow(window);
			}
			else{
				if (event.key.type == SDL_KEYDOWN) {
					switch (event.key.keysym.scancode) {
					case SDL_SCANCODE_UP:
						movUp = true;
						break;
					case SDL_SCANCODE_RIGHT:
						movRight = true;
						break;
					case SDL_SCANCODE_DOWN:
						movDown = true;
						break;
					case SDL_SCANCODE_LEFT:
						movLeft = true;
						break;
					}
				}
				if (event.key.type == SDL_KEYUP) {
					switch (event.key.keysym.scancode) {
					case SDL_SCANCODE_UP:
						movUp = false;
						break;
					case SDL_SCANCODE_RIGHT:
						movRight = false;
						break;
					case SDL_SCANCODE_DOWN:
						movDown = false;
						break;
					case SDL_SCANCODE_LEFT:
						movLeft = false;
						break;
					}
				}
				
				/*if (state[SDL_SCANCODE_DOWN])
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
				}	*/
			}
		}
		if (movUp == true) {
			rect.y--;
		}
		if (movDown == true) {
			rect.y++;
		}
		if (movLeft == true) {
			rect.x--;
		}
		if (movRight == true) {
			rect.x++;
		}
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, back_tx, 0, 0);
		SDL_RenderCopy(renderer, goku_tx, 0, &rect);
		SDL_RenderCopy(renderer, shoot_tx, 0, &shot);
		
		//SDL_RenderFillRect(renderer, &rect);
		//SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		
		//SDL_RenderFillRect(renderer, &rect);
		//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		//SDL_RenderFillRect(renderer, &shot);
		shot.x++;
		
		SDL_RenderPresent(renderer);
	}
	IMG_Quit();
	SDL_Quit();
	return 0;
}