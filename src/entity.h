#include <SDL2/SDL.h>
#include "renderer.h"

class Entity {
    Renderer* renderer;  
    InputManager* inputManager;
public:
    Entity(InputManager* inputManager): inputManager(inputManager) {}
    virtual void render();
    virtual void update(float deltaTime);
};