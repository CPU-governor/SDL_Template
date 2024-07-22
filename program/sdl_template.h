#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>

// Global variables
SDL_Window *win = NULL;
SDL_Renderer *ren = NULL;
SDL_Texture *tex = NULL;
SDL_Surface *surf = NULL;
bool active = true; // so you can use while (active){ //SDL events}
bool running = true; // so you can use while (running){ //SDL events}

// =============INITIALIZATION, WINDOW, EVENTS===========================

bool init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return false;
    }
    win = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_RESIZABLE);
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
    // init external libs
    IMG_Init(IMG_INIT_PNG);
    return true;
}

void quit() {
    if (tex) {
        SDL_DestroyTexture(tex);
    }
    if (ren) {
        SDL_DestroyRenderer(ren);
    }
    if (win) {
        SDL_DestroyWindow(win);
    }
    SDL_Quit();
}

void handle_events() {
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

void debug() {
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

// =============COLOR, DRAW(RECT, TRI, CIR)===========================

typedef struct {
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
} Color;

typedef enum {
    FILLED,
    OUTLINE
} ShapeType;

void draw_rectangle(Color color, int width, int height, int xpos, int ypos, ShapeType type) {
    SDL_Rect rect;
    rect.x = xpos; // X position
    rect.y = ypos; // Y position
    rect.w = width; // Width
    rect.h = height; // Height

    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255); // Black background
    SDL_RenderClear(ren);

    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a); // Rectangle color
    // Draw based on the type
    if (type == FILLED) {
        SDL_RenderFillRect(ren, &rect);
    } else if (type == OUTLINE) {
        SDL_RenderDrawRect(ren, &rect);
    }
    SDL_RenderPresent(ren);
}

void draw_triangle(Color color, int x1, int y1, int x2, int y2, int x3, int y3) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
    
    // Draw the three sides of the triangle
    SDL_RenderDrawLine(ren, x1, y1, x2, y2);
    SDL_RenderDrawLine(ren, x2, y2, x3, y3);
    SDL_RenderDrawLine(ren, x3, y3, x1, y1);

    SDL_RenderPresent(ren);
}

void draw_circle(Color color, int cx, int cy, int radius) {
    SDL_SetRenderDrawColor(ren, color.r, color.g, color.b, color.a);
    int d = 3 - 2 * radius;
    int x = 0, y = radius;

    while (y >= x) {
        SDL_RenderDrawPoint(ren, cx + x, cy + y);
        SDL_RenderDrawPoint(ren, cx - x, cy + y);
        SDL_RenderDrawPoint(ren, cx + x, cy - y);
        SDL_RenderDrawPoint(ren, cx - x, cy - y);
        SDL_RenderDrawPoint(ren, cx + y, cy + x);
        SDL_RenderDrawPoint(ren, cx - y, cy + x);
        SDL_RenderDrawPoint(ren, cx + y, cy - x);
        SDL_RenderDrawPoint(ren, cx - y, cy - x);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
    SDL_RenderPresent(ren);
}

// =============IMG, AUDIO LOAD===========================

void load_img(const char *path) {
    SDL_Surface *img = IMG_Load(path);
    SDL_Texture *temp_tex = SDL_CreateTextureFromSurface(ren, img);
    SDL_RenderCopy(ren, temp_tex, NULL, NULL);
    SDL_RenderPresent(ren);
}

/* example usage 1
int main (){
    init("test", 480, 320);
    while (active) {
        handle_events();
    
        // Update/rendering logic can go here
    
    }
    quit();
    return 0;
}
*/
