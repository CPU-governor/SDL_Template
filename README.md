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

        clear_screen(BLACK);
        
        draw_rectangle(RED, 200, 200, 400, 400, FILLED);
        draw_rectangle(WHITE, 200, 200, 250, 50, OUTLINE);
        
        present();
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
- [x] Events handling
- [x] Draw function (functions to draw shapes)
- [x] Write Text function
- [ ] Load media function

### Advanced Features
- [ ] Language bindings
- [ ] Documentations
- [ ] API improvements
- [ ] Plugin support
