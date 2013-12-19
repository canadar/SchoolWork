#include "MapEditor.h"
#include <SDL.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>

MapEditor::MapEditor()
{
	SDL_Init(SDL_INIT_EVERYTHING); //initializing everything (SDL)
	window=SDL_SetVideoMode(800,600,32,SDL_SWSURFACE); //this is initializing our window // I put null in there until i figure that part out.
	blocks=load_image("images/tiles.bmp");  //loads the images for the tiles in the sprite sheet
	Uint32 color = SDL_MapRGB(window->format, 0x00,0x00,0x00);
	
	//Player Information
	//player=load_image(NULL);  // loads the images for the player  //this is null until i get some images
	//player_rect.x=0;  //sets the enemy x coords.
	//player_rect.y=0;  //sets the enemy y coords.
	//player_rect.w=0;  //sets the width
	//player_rect.h=0;  //sets the height of the enemy

	//this stores a list of all the tiles for easy access so it can be
	//accessed easily
	for(int i=0;i<TILECOUNT;i++)
	{
		blocks_rect[i].x=i*32;  
		blocks_rect[i].y=0;
		blocks_rect[i].w=32;
		blocks_rect[i].h=32;
	}

	cur_tile=0;  
	//this makes a vector that is MAXTILEWIDTH long and MAXTILEHEIGHT down
	for(int i=0;i<MAXTILEHEIGHT;i++)
	{
		std::vector<int> mapVec;
		for(int j=0; j<MAXTILEWIDTH;j++)
		{
			mapVec.push_back(0); //puts in nothing everywhere
		}
		map.push_back(mapVec);
	}
	coord.x=0;
	coord.y=0;
	coord.w=0;
	coord.h=0;
}


MapEditor::~MapEditor()
{
	SDL_FreeSurface(blocks);
	SDL_FreeSurface(window);
	//SDL_FreeSurface(patrolEnemy);
	SDL_Quit();
}

void MapEditor::startMapMaking()
{
	bool go=true;
	SDL_Event event;
	//where the mouse is pointing on the screen.
	int x;
	int y;
	while(go)
	{
		//startGame=SDL_GetTicks();  //use the current time with start.
		while(SDL_PollEvent(&event))
		{
		//switch statement for which event is happening
			switch(event.type)
			{
			//exit if we stop the program
				case SDL_QUIT:
					go=false;
					break;

				case SDL_MOUSEBUTTONDOWN:
					if(event.button.button==SDL_BUTTON_RIGHT)  //if you click the right button
					{
						x=event.button.x;  //get the x coordinate
						y=event.button.y;  //get the y coordinate
						//these make sure that as long as the click within a tile 
						//the editor will go to the far left side of the tile to set
						// it.  This is unless the user doesn't hit a multiple of 32. Then it will be on the
						//right and for the y it will be the top unless the user gets a multiple of 32
						//then it will be the bottom of the tile on either right or left.
						x=x-(x%32); 
						y=y-(y%32);
						cur_tile++;
						if(cur_tile>=TILECOUNT)
						{
							cur_tile=0;
						}
					}
					else if(event.button.button==SDL_BUTTON_LEFT)  //if you click the left button
					{
						x=event.button.x;  //get the x coordinate
						y=event.button.y;  //get the y coordinate
						//these make sure that as long as the click within a tile 
						//the editor will go to the far left side of the tile to set
						// it.  This is unless the user doesn't hit a multiple of 32. Then it will be on the
						//right and for the y it will be the top unless the user gets a multiple of 32
						//then it will be the bottom of the tile on either right or left.
						x=x-(x%32); 
						y=y-(y%32);
						map[((int)(y/32)+coord.y/32)][((int)(x/32)+coord.x/32)]=cur_tile+1;
						//[((int)(y/32)+coord.y/32)][((int)(x/32)+coord.x/32)] is the indecy of the 
						//vector that houses our list of sprites so we get the correct sprite that is housed there
					}
					break;

				case SDL_MOUSEMOTION:  //if the mouse moves
					x=event.motion.x;
					y=event.motion.y;
					x=x-(x%32);
					y=y-(y%32);
					break;

			case SDL_KEYDOWN:
					if(event.key.keysym.sym==SDLK_k)//k for keep
					{
						saveMap();
					}
					break;
			}//end switch statement
		}//End polling while loop

		SDL_FillRect(window,&window->clip_rect,color);
		mapViewer();
		SDL_Rect temp={x,y}; //gets the x and y values that
		//were saved by the click or mouse movement.
		SDL_BlitSurface(blocks,&blocks_rect[cur_tile],window,&temp);
		SDL_Flip(window); 
	}

}

SDL_Surface* MapEditor::load_image(const char* c)
{
	SDL_Surface* temp=SDL_LoadBMP(c);  //loads the BMP file
	SDL_Surface* cTemp=SDL_DisplayFormat(temp);  //covert to correct format for screen
	SDL_FreeSurface(temp);  // Not needed beyond this point so we might as well free it
	SDL_SetColorKey(cTemp,SDL_SRCCOLORKEY, SDL_MapRGB(window->format,0xff,0x00,0xff)); 
	std::cout<<"Sprite Sheet Loaded Successfully!";
	return cTemp;
}

void MapEditor:: mapViewer()
{
	int start=(coord.x-coord.x%32)/32;
	int end=(coord.x+coord.w+(32-(coord.x+coord.w)%32))/32;

	if(end>map[0].size())//if too big
	{
		end=map[0].size();  //then change it to be the size of the map
	}
	
	if(start<0) //if too small
	{
		start=0;
	}
	for(int i=0;i<map.size();i++)
	{
		for(int j=0;j<map[0].size();j++)
		{
			if(map[i][j]!=0)
			{
				SDL_Rect blockrect={(map[i][j]-1)*32,0,32,32};
				SDL_Rect destrect={j*32-coord.x,i*32};
				SDL_BlitSurface(blocks,&blockrect,window,&destrect);
			}
		}
	}
}
void MapEditor:: saveMap()
{
	char h [30];  //this is for the file name
	sprintf(h,"%d", time(0));//get "random file name"
	strcat(h,".map");       //make it a  .map 
    std::ofstream out(h);   //open the filestream for output 
    out<<map[0].size()<<" "<< map.size()<<std::endl; 
    for(int i=0;i<map.size();i++)   
    {
      for(int j=0;j<map[0].size();j++)
      {
         out << map[i][j] << " ";    
      }
      out << std::endl;
   }

	std::cout << "File Saved Successfully as: " << h << "." << std::endl;
}