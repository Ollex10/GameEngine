#include <SDL.h>
#include "InputManager.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2
    SDL_Window* window = SDL_CreateWindow("SDL2 Input Example", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    InputManager inputManager;

    bool running = true;
    while (running) {
        inputManager.Update(); // Check for input each frame

        if (inputManager.IsKeyPressed(SDLK_ESCAPE)) {
            running = false; // Exit the game if escape is pressed
        }

        // Other game logic here...

        SDL_RenderClear(renderer);
        // Render game objects...
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
