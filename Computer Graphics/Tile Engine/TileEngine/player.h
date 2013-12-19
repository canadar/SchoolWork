#include<SDL.h>
#include<iostream>
#include<fstream>

#pragma once
class player
{
public:
	player(const char* spriteSheet, SDL_Surface* p_screen);
	~player(void);
	void playerInput(SDL_Event* event);
	void drawPlayer();
	void updatePlayer(bool* dir);

private:
	int playerWidth;
	int playerHeight;
	int counter;
	int speed;
	static const int OFFSET = 32;
	bool direction[4], flipFrame;
	SDL_Rect playerRect, clipRect;
	SDL_Surface* playerSpriteSheet, *screen;
	SDL_Surface* loadImage(const char* fileName);

};

