#include <SDL.h>
#include "InputManager.h"
#include "Game.h"
#include <iostream>


    Game::Game() {}

    Game::~Game() {}

    void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

        int flags = 0;
        if (fullscreen) {
            flags = SDL_WINDOW_FULLSCREEN;
        
        }

        if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
            window = SDL_CreateWindow(title, xpos, ypos, width, height,flags);
            if (window == nullptr) {
                std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
                isRunning = false;
                return;
            }
            renderer = SDL_CreateRenderer(window, -1, 0);
            if (renderer== nullptr) {
                std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
                SDL_DestroyWindow(window);
                isRunning = false;
                return;
            }
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            isRunning = true;

        }
        else {
            std::cout << "SDL Initialization failed: " << SDL_GetError() << std::endl;
            isRunning = false;
        }
    
    
    }
    void Game::handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;

            }
        }
    
    }

    void Game::update() {}

    void Game::render() {
        SDL_RenderClear(renderer);
        //Add stuff to render
        SDL_RenderPresent(renderer);

    
    }

    void Game::clean() {
        if (renderer) {
            SDL_DestroyRenderer(renderer);
            renderer = nullptr;
        }

        if (window) {
            SDL_DestroyWindow(window);
            window = nullptr;
        }
        
        
        SDL_Quit();
    }

