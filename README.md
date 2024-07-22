# SDL_Template
A template for SDL graphics library that abstract's functions in a way that makes them easier to use, this is a wrapper for SDL that works interchangeably with it.

### Example usage
just copy the ```sdl_template.h``` file to your project directory and you can then call functions from it.

below is an example program that draws shapes
```c
#include<SDL2/SDL.h> // you need to include SDL for it to work
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
```
 when compiled, this is what you will get:
 ![ouput](../tutorials_and_wiki/shape.png)
 
# To do list
Below contains a list of tasks that need to be implemented for the project.

### Core Features
- [x] Init and Quit function (to initialize and close SDL)
- [ ] Events handling
- [ ] Draw function (functions to draw shapes)
- [ ] Load media function

### Advanced Features
- [ ] Language bindings
- [ ] Documentations
- [ ] API improvements
- [ ] Plugin support
