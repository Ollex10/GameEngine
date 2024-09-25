// InputManager.h
#pragma once
#include <SDL.h>
#include <unordered_map>

class InputManager {
public:
    InputManager(); //Constructor to initialize joystick support
    ~InputManager(); // Destructor to clean up

    void Update(); // Called every frame to process input
    bool IsKeyPressed(SDL_Keycode key); // Check if a key is currently pressed
    bool IsKeyReleased(SDL_Keycode key); // Check if a key is released
    bool IsMouseButtonPressed(int button);
    void GetMousePosition(int& x, int& y);
    bool IsJoystickButtonPressed(int button);
    int GetJoystickAxis(int axis);

private:
    std::unordered_map<SDL_Keycode, bool> keyState; // Map to store key states
    Uint32 mouseState; //Tracks mouse button state Uint32 is a type definition in SDL2
    int mouseX, mouseY;
    SDL_Joystick* joystick; //Pointer to the joystick
    std::unordered_map<int, bool> joystickButtonState; //Stores joystick button states
    int joystickAxis[2]; //For storing joystick axis values
};
