#include<SDL2/SDL.h>
#include"sdl_template.h"
int main() {
    init("window", 800, 600);

    while (active) {
        handle_events();

        // Clear the screen once per frame
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // Black background
        SDL_RenderClear(ren);
		// draw shapes (optional)
        Color red = {255, 0, 0, 255};
        Color color = {0, 0, 255, 255};
        Color color2 = {0, 140, 255, 255};
        draw_rectangle(color, 200, 200, 400, 400, FILLED);
        draw_rectangle(color, 200, 200, 250, 50, OUTLINE);
        draw_circle(color2, 100,100,100, FILLED); 
        draw_triangle(red, 400, 300, 450, 300, 425, 350, FILLED);

        // Present the rendered frame
        SDL_RenderPresent(ren);
    }

    quit();
    return 0;
}
