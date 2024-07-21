#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

//CONTENTS OF THIS CODE
/*
 Global variables >>> line 15
 init function
 quit function
 event function
 debug function


*/

// Global variables
 SDL_Window *win = NULL;
 SDL_Renderer *ren = NULL;
 SDL_Texture *tex = NULL;
 SDL_Surface *surf=NULL;
 bool active = true; // so you can use while (active){ //SDL events}
 bool runing = true; // so you can use while (runing){ //SDL events}

bool init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }
    win = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_SHOWN);
    if (win == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        SDL_DestroyWindow(win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }
    return true;
}

void quit() {
    if (tex) {
        SDL_DestroyTexture(tex);
    }if (ren) {
        SDL_DestroyRenderer(ren);
    }
    if (win) {
        SDL_DestroyWindow(win);
    }
    SDL_Quit();
}
void events() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                active = false;
                break;
            // Handle other events here if needed
            default:
                break;
        }
    }
}
void debugger(){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	        printf("SDL_Init Error: %s\n", SDL_GetError());
	    }
	    if (win == NULL) {
	        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
	        SDL_Quit();
	    }
	    if (ren == NULL) {
	        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
	    }
}

/* example usage 1
int main (){
	init("test",480,320);
	while (active) {
	  events();
	
	        // Update/rendering logic can go here
	
	}
	quit();
	return 0;
}

*/
