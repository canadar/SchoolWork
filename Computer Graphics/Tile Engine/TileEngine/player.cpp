#include "player.h"


player::player(const char* fileName, SDL_Surface* p_screen)
{
	screen = p_screen;
	playerRect.x = 300;
	playerRect.y = 300;
	clipRect.x=0;
	clipRect.y =0;
	clipRect.w=28;
	clipRect.h=32;
	playerSpriteSheet = loadImage(fileName);
	flipFrame = true;
	speed = 1;
	counter = 16;
}


player::~player(void)
{
	SDL_FreeSurface(playerSpriteSheet);
}

SDL_Surface* player::loadImage(const char* fileName){

	SDL_Surface* load = SDL_LoadBMP(fileName);
	SDL_Surface* spriteSheet = SDL_DisplayFormat(load);
	SDL_SetColorKey(spriteSheet,SDL_SRCCOLORKEY,SDL_MapRGB(screen->format,0xFF,0x00,0xFF)); //Eliminates magenta background color from images

	SDL_FreeSurface(load);
	std::cout << "Player Spritesheet loaded Successfully!" << std::endl;
	return spriteSheet;
}

void player::drawPlayer(){
	//std::cout << "x " << playerRect.x << " , " << "y " << playerRect.y << std::endl;
	SDL_Rect destRect = playerRect;
	SDL_Rect sectionRect = clipRect;
	SDL_BlitSurface(playerSpriteSheet,&clipRect, screen, &destRect);
}


void player::updatePlayer(bool* dir){

	if(counter >= 64){
		counter = 0;
		if(flipFrame){
			flipFrame = false;
		}
		else if(!flipFrame){
			flipFrame = true;
		}

		
	}

	if(dir[0]){
		//std::cout<<"up"<<std::endl;
		playerRect.y -= speed;
		counter++;
		if(flipFrame){
			clipRect.x = 28*4 + OFFSET;
		}
		if(!flipFrame){
			clipRect.x = 28*4;
		}
	}
	if(dir[1]){
		//std::cout<<"left"<<std::endl;
		playerRect.x -= speed;
		if(flipFrame){
			clipRect.x = 28*0 + OFFSET;
		}
		if(!flipFrame){
			clipRect.x = 28*0;
		}
		counter++;

	}
	if(dir[2]){
		//std::cout<<"down"<<std::endl;
		playerRect.y += speed;
		if(flipFrame){
			clipRect.x = 28*2 + OFFSET;
		}
		if(!flipFrame){
			clipRect.x = 28*2;
		}
		counter++;
	}
	if(dir[3]){
		//std::cout<<"right"<<std::endl;
		playerRect.x += speed;
		if(flipFrame){
			clipRect.x = 28*6 + OFFSET;
		}
		if(!flipFrame){
			clipRect.x = 28*6;
		}
		counter++;
	}
}
