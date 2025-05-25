#pragma once
#include "renderer.h"
#include "input_manager.h"
#include <vector>
 #include "entity.h"

class Game {
    Renderer* renderer;
    std::vector<Entity*> entities;

public:
    Game(Renderer* renderer);
    ~Game();
    void update(float deltaTime);
    void render();
    void addEntity(Entity* entity);
};

