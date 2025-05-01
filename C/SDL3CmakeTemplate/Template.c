#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_surface.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (result < 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("SDL3 Template", 600, 400, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        SDL_Log("SDL_CreateWindow: %s", SDL_GetError());
        return -2;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        SDL_Log("SDL_CreateRenderer: %s", SDL_GetError());
        return -3;
    }

    SDL_Log("SDL3 Initialized");

    SDL_Event event;
    SDL_FRect rect;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                SDL_Log("SDL3 Event Quit");
                quit = 1;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0xff, 0xff, 0xff);

        rect = (10f, 10f, 5f, 5f)

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF)
        
        SDL_RenderFillRect(renderer, &rect)

        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }

    SDL_Log("SDL3 Shutdown");
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
