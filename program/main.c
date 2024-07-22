#include<SDL2/SDL.h>
#include"sdl_template.h"
int main(){
	init("window",800,600);
	while (active){
	handle_events();
	Color color={0,0,255,255};
	draw_rectangle(color,0,0,200,200,FILLED);
	SDL_RenderPresent(ren);
	}
	quit();
}
