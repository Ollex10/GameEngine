// Main.cpp
#include "Game.h"
#include "InputManager.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Game game;
    game.init("Game Title", 100, 100, 800, 600, false);  // Initialize the game

    InputManager inputManager;

    while (game.running()) {  // Main game loop
        game.handleEvents();
        inputManager.Update();

        if (inputManager.IsKeyPressed(SDLK_ESCAPE)) {
            game.clean();
            break;
        }

        game.update();
        game.render();
    }

    return 0;
}
