#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_keycode.h>

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* softRend = NULL;
    SDL_Surface* softSurface = NULL;
    softSurface = SDL_CreateRGBSurface(SDL_RENDERER_SOFTWARE, 800, 600, 8, 0, 0, 0, 0);

    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    if (result < 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("SDL2 Template", 50, 50, 800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        return -2;
    }

    softRend = SDL_CreateSoftwareRenderer(softSurface);
    if (softRend == NULL) {
        SDL_Log("SDL_CreateSoftwareRenderer Error: %s", SDL_GetError());
        return -3;
    }

    SDL_Log("SDL2 Initialized");

    SDL_Event event;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                quit = 1;
                break;
            }
        }

        SDL_SetRenderDrawColor(softRend, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(softRend);

        SDL_RenderPresent(softRend);
        SDL_Delay(1);
    }

    SDL_Log("SDL2 Shutdown");
    SDL_DestroyRenderer(softRend);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}