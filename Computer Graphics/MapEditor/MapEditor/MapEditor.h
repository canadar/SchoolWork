#pragma once
#include <SDL.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>


#ifndef MapEditor_H
#define MapEditor_H
class MapEditor
{
private:
	static const int TILECOUNT=8;  //number of tiles in sprite sheet
	SDL_Rect coord;
	SDL_Rect blocks_rect[TILECOUNT];
	//SDL_Rect player;  //players sprite.
	SDL_Surface*  window,*blocks;//*patrolEnemy;  //screen
	int cur_tile;
	Uint32 color;
	std::vector<std::vector<int>> map;
	void viewMap();  //make the map appear on the screen.
	static const int MAXTILEWIDTH = 25;
	static const int MAXTILEHEIGHT = 19;
public:
	MapEditor();
	~MapEditor();
	void startMapMaking();  //start the game.
	void saveMap();  //save the map
	SDL_Surface* MapEditor::load_image(const char* c);//load images in
	void MapEditor:: mapViewer(); //make the map show up 
};
#endif
