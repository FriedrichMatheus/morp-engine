#pragma once
#include <SDL2/SDL.h>
#include <unordered_map>

class InputManager {
    std::unordered_map<SDL_Keycode, bool> keyState;

public:
    InputManager();

    void updateEvent(const SDL_Event& e);
    bool isKeyPressed(SDL_Keycode key);
    void reset();
};