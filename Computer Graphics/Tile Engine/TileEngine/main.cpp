#include <iostream>
#include <SDL.h>
#include "TileEngine.h"
#include "player.h"


int main(int __argc, char *argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);
	int SCREEN_WIDTH = 800;
	int SCREEN_HEIGHT = 600;
	int framesPerSecond = 32;
	SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
	bool direction[4] = {0,0,0,0};
	Uint32 start = SDL_GetTicks();
	Uint32 color = SDL_MapRGB(screen->format, 0x00,0x00,0x00);
	bool running = true;
	SDL_Event event;
	
	SDL_WM_SetCaption("Computer Graphics Final", NULL);
	TileEngine engine = TileEngine(screen);

	player p = player("images/player.bmp",screen);
	engine.loadMap("maps/1387444383.map");//loads the map file


	while(running){
		while(SDL_PollEvent(&event)){
			switch(event.type){
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
				case SDLK_w:
					direction[0] = 1;
					break;
				case SDLK_a:
					direction[1] = 1;
					break;
				case SDLK_s:
					direction[2] = 1;
					break;
				case SDLK_d:
					direction[3] = 1;
					break;
				}
				break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym){
				case SDLK_w:
					direction[0] = 0;
					break;
				case SDLK_a:
					direction[1] = 0;
					break;
				case SDLK_s:
					direction[2] = 0;
					break;
				case SDLK_d:
					direction[3] = 0;
					break;
				break;
				}
			}
		}//Event handling loop
		//player
		SDL_FillRect(screen,&screen->clip_rect,color);
		p.updatePlayer(direction);
		engine.drawMap();//draws the tiles
		p.drawPlayer();

		//draw map
		SDL_Flip(screen);//Draws the surface "Screen" to the window.
		if(1000/framesPerSecond>(SDL_GetTicks()-start))
			SDL_Delay(1000/framesPerSecond-(SDL_GetTicks()-start)); //Limits the framerate
	}//Main game loop

	SDL_FreeSurface(screen); //deallocate memory for this surface
	SDL_Quit();
	return 0;
}