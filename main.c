#include"SDL_template.h"
int main (){
	init("test",480,320);
	while (active) {
	  events();
	
	        // Update/rendering logic can go here
	
	}
	quit();
	return 0;
}
