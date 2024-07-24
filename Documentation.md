# sdl_template Documentation

## Overview
This wrapper simplifies the use of SDL2 for creating graphical applications. It includes initialization, event handling, drawing shapes, loading images, and rendering text.

## Global Variables
- `SDL_Window *win`: The main application window.
- `SDL_Renderer *ren`: The renderer for the window.
- `bool active`: Controls the main loop of the application.

## Initialization and Cleanup

### `bool init(const char *title, int width, int height)`
Initializes SDL, creates a window, and sets up the renderer.
- **Parameters:**
  - `title`: Title of the window.
  - `width`: Width of the window.
  - `height`: Height of the window.
- **Returns:** `true` if initialization is successful, `false` otherwise.

### `void quit()`
Cleans up and shuts down SDL, TTF, and IMG libraries.

## Event Handling

### `void handle_events()`
Polls and processes SDL events. Sets `active` to `false` when the window is closed.

## Debugging

### `void debug()`
Prints the status of SDL initialization, window, and renderer.

## Drawing Functions

### Color Structure
```c
typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} Color;
```
Represents a color with red, green, blue, and alpha components.

### ShapeType Enumeration
```c
typedef enum {
    FILLED,
    OUTLINE
} ShapeType;
```
Defines whether a shape should be filled or outlined.

### `void draw_rectangle(Color color, int width, int height, int xpos, int ypos, ShapeType type)`
Draws a rectangle.
- **Parameters:**
  - `color`: The color of the rectangle.
  - `width`: The width of the rectangle.
  - `height`: The height of the rectangle.
  - `xpos`: The x-coordinate of the top-left corner.
  - `ypos`: The y-coordinate of the top-left corner.
  - `type`: `FILLED` or `OUTLINE`.

### `void draw_triangle(Color color, int x1, int y1, int x2, int y2, int x3, int y3, ShapeType type)`
Draws a triangle.
- **Parameters:**
  - `color`: The color of the triangle.
  - `x1`, `y1`: Coordinates of the first vertex.
  - `x2`, `y2`: Coordinates of the second vertex.
  - `x3`, `y3`: Coordinates of the third vertex.
  - `type`: `FILLED` or `OUTLINE`.

### `void draw_circle(Color color, int cx, int cy, int radius, ShapeType type)`
Draws a circle.
- **Parameters:**
  - `color`: The color of the circle.
  - `cx`: The x-coordinate of the center.
  - `cy`: The y-coordinate of the center.
  - `radius`: The radius of the circle.
  - `type`: `FILLED` or `OUTLINE`.

## Screen Management

### `void clear_screen(Color color)`
Clears the screen with the specified color.
- **Parameters:**
  - `color`: The color to clear the screen with.

### `void present()`
Presents the current rendering to the screen.

## Image Loading

### `void load_img(const char *path)`
Loads and displays an image.
- **Parameters:**
  - `path`: Path to the image file.

## Text Rendering

### `int load_font(const char *path, int size)`
Loads a font.
- **Parameters:**
  - `path`: Path to the font file.
  - `size`: Size of the font.
- **Returns:** `0` if successful, `-1` otherwise.

### `int write_text(const char *text, Color color)`
Renders text and displays it at the top-left corner.
- **Parameters:**
  - `text`: The text to render.
  - `color`: The color of the text.
- **Returns:** `0` if successful, `-1` otherwise.

### `int draw_text(const char *text, int x, int y, int w, int h, Color color)`
Renders text and displays it at specified coordinates.
- **Parameters:**
  - `text`: The text to render.
  - `x`: The x-coordinate of the top-left corner of the text.
  - `y`: The y-coordinate of the top-left corner of the text.
  - `w`: The width of the text area.
  - `h`: The height of the text area.
  - `color`: The color of the text.
- **Returns:** `0` if successful, `-1` otherwise.

## Example Usage

```c
#include<SDL2/SDL.h>
#include "sdl_template.h"

int main( ) {
    init("title", 800, 600);

    load_font("path/to/font.ttf", 24);

    while (active) {
        handle_events();

        clear_screen(BLACK);

        draw_rectangle(RED, 100, 50, 200, 150, FILLED);
        draw_triangle(GREEN, 400, 300, 450, 350, 350, 350, OUTLINE);
        draw_circle(BLUE, 600, 400, 50, FILLED);

        draw_text("Hello, SDL2!", 50, 50, 200, 50, WHITE);

        present();
    }

    quit();
    return 0;
}
```

This documentation covers the basic usage of the SDL2 wrapper and provides a clear understanding of how to initialize, handle events, draw shapes, load images, and render text using the provided functions.