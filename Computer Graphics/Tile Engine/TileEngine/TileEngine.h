#include<vector>
#include<fstream>
#include <iostream>
#include <SDL.h>

#pragma once
class TileEngine
{
public:
	TileEngine(void);
	TileEngine(SDL_Surface* screen);
	~TileEngine(void);
	void loadMap(const char* mapName);
	void drawMap();
	SDL_Surface* loadSpriteSheet(const char* file);

private:
	int tileWidth;
	int tileHeight;
	int tileSize;
	SDL_Surface *tile, *engineScreen;
	std::vector<std::vector<int>> map; //2d vector for varying map sizes
};

