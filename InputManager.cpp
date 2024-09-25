

// InputManager.cpp
#include "InputManager.h"

void InputManager::Update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            keyState[event.key.keysym.sym] = true;
        }
        if (event.type == SDL_KEYUP) {
            keyState[event.key.keysym.sym] = false;
        }
    }
    mouseState = SDL_GetMouseState(&mouseX, &mouseY);
}

bool InputManager::IsKeyPressed(SDL_Keycode key) {
    return keyState[key]; // Return true if the key is pressed
}

bool InputManager::IsKeyReleased(SDL_Keycode key) {
    return !keyState[key]; // Return true if the key is released
}

bool InputManager::IsMouseButtonPressed(int button) {
    return mouseState & SDL_BUTTON(button);
}

void InputManager::GetMousePosition(int& x, int& y) {
    x = mouseX;
    y = mouseY;
}
