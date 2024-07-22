#include<SDL2/SDL.h>
#include"sdl_template.h"
int main() {
    init("window", 800, 600);

    while (active) {
        handle_events();

        // Clear the screen once per frame
        clear_screen(BLACK);
		// draw shapes (optional)
       load_font("FreeMono.ttf",24);
       write_text("Priscilla",WHITE);
        // Present the rendered frame
        present();
      }

    quit();
    return 0;
}
