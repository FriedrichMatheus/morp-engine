#pragma once
#include <SDL2/SDL.h>
#include "renderer.h"

class Entity {
protected:
    Renderer* renderer;  
public:
    Entity(Renderer* renderer);
    virtual ~Entity();
    virtual void render();
    virtual void update(float deltaTime);
};