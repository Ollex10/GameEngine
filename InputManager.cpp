

// InputManager.cpp
#include "InputManager.h"

InputManager::InputManager() {
    SDL_InitSubSystem(SDL_INIT_JOYSTICK); //Initialize joystick subsystem
    if (SDL_NumJoysticks() > 0) {
        joystick = SDL_JoystickOpen(0);//Open the first availabe joystick
    
    }
}

InputManager::~InputManager() {
    if (joystick) {
        SDL_JoystickClose(joystick);//CLose the joystick
   
       }
    
}

void InputManager::Update() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            keyState[event.key.keysym.sym] = true;
        }
        if (event.type == SDL_KEYUP) {
            keyState[event.key.keysym.sym] = false;
        }


        mouseState = SDL_GetMouseState(&mouseX, &mouseY);
       
        
    if (event.type == SDL_JOYBUTTONDOWN) {
        joystickButtonState[event.jbutton.button] = true; //Button pressed
    
        }
    if (event.type == SDL_JOYBUTTONUP) {
        joystickButtonState[event.jbutton.button] = false; //Button released
        }
    if (event.type == SDL_JOYAXISMOTION) {
        joystickAxis[event.jaxis.axis] = event.jaxis.value;//Update axis value
    
         }
        }

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

bool InputManager::IsJoystickButtonPressed(int button) {
    return joystickButtonState[button];
}

int InputManager::GetJoystickAxis(int axis) {
    return joystickAxis[axis];

}
