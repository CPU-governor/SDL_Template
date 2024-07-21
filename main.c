#include"SDL_template.h"
#include<SDL2/SDL.h>
int main (){
	init("test",480,320);
	while (active) {
	  events(); // this already handles SDL QUIT case, just creat a new Switch statement and check new cases based on your program
	
	        // Update/rendering logic can go here
	 
		Color red = {255, 0, 0, 255}; // Define a red color
		Draw_rect(red, 0, 0, 200, 200,FILLED);
		Draw_rect(red, 200, 200, 200, 200,OUTLINE);
	//	Draw_triangle(red, 50, 55, 60, 20, 66, 80);
	//	Draw_circle(red,140,55,300);
	}
	quit();
	return 0;
}
