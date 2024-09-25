// InputManager.h
#pragma once
#include <SDL.h>
#include <unordered_map>

class InputManager {
public:
    void Update(); // Called every frame to process input
    bool IsKeyPressed(SDL_Keycode key); // Check if a key is currently pressed
    bool IsKeyReleased(SDL_Keycode key); // Check if a key is released
    bool IsMouseButtonPressed(int button);
    void GetMousePosition(int& x, int& y);

private:
    std::unordered_map<SDL_Keycode, bool> keyState; // Map to store key states
    Uint32 mouseState; //Tracks mouse button state Uint32 is a type definition in SDL2
    int mouseX, mouseY;
};
