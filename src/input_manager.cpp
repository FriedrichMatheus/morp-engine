#include "input_manager.h"

InputManager::InputManager() : keyState() {}

void InputManager::updateEvent(const SDL_Event& event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN: {
        if (!event.key.repeat) {
            SDL_Keycode key = event.key.keysym.sym;
            SDL_Log("Key pressed: %s (%d)", SDL_GetKeyName(key), key);
            keyState[key] = true;
        } 
        break;
    } 
    case SDL_KEYUP: {
        SDL_Keycode key = event.key.keysym.sym;
        SDL_Log("Key unpressed: %s (%d)", SDL_GetKeyName(key), key);
        keyState[key] = false;
        break;
    }
    default:
        break;
    }
}

bool InputManager::isKeyPressed(SDL_Keycode key) {
    return keyState[key];
}