#include "TileEngine.h"

TileEngine::TileEngine(SDL_Surface* screen)
{
	tileSize = 32;
	tileWidth = 32;
	tileHeight = 32;
	engineScreen = screen;
	tile = loadSpriteSheet("images/spritesheet.bmp");
	//background = loadSpriteSheet("images/background.bmp");
}

TileEngine::~TileEngine(void)
{
	//SDL_FreeSurface(background);
	SDL_FreeSurface(tile);
}

SDL_Surface *TileEngine::loadSpriteSheet(const char* file){

	SDL_Surface* load = SDL_LoadBMP(file);
	SDL_Surface* spriteSheet = SDL_DisplayFormat(load);
	SDL_SetColorKey(spriteSheet,SDL_SRCCOLORKEY,SDL_MapRGB(engineScreen->format,0x00,0xFF,0xFF)); //Eliminates magenta background color from images

	SDL_FreeSurface(load);
	std::cout << "Spritesheet loaded Successfully!" << std::endl;
	return spriteSheet;
}

//Loop throught the map file and gather the assigned tiles.
void TileEngine::loadMap(const char* mapName){
	int width;
	int height;
	int current;

	std::ifstream inFile(mapName);
	if(!inFile.is_open()){
		std::cout << "Error opening map" << std::endl;
		return;
	}
	inFile >> width;
	inFile >> height;

	for(int i = 0; i <height; i++){
		std::vector<int> tmpVector;
		for(int j = 0; j<width; j++){
			if(inFile.eof()){
				std::cout <<"reached end of file too early"<<std::endl;
			}
			inFile >> current; // Obtain tile element at current position in the file.
			//If or switch statement for selecting what the number represents per tile.
			if(current >= 0 && current <= 10){
				tmpVector.push_back(current);
				
			}
			else{
				tmpVector.push_back(0);
			}
		}
		map.push_back(tmpVector);
	}
	std::cout << "Map Loaded Successfully!" << std::endl;
	inFile.close();
}

//Generate the map
void TileEngine::drawMap(){
	
	for(int i = 0; i < map.size(); i++){
		for(int j = 0; j < map[i].size(); j++){
			if(map[i][j] != 0){
				SDL_Rect tileBlock = {map[i][j]*tileSize,0,tileWidth, tileHeight};
				SDL_Rect tileDestination = {j*tileSize,i*tileSize};
				SDL_BlitSurface(tile,&tileBlock, engineScreen, &tileDestination);
			}
		}
	}
}