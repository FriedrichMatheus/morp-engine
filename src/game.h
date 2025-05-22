#include "renderer.h"
#include "input_manager.h"
#include <vector>
#include "entity.h"

class Game{
    Renderer* renderer;
    InputManager* inputManager;
    std::vector<Entity*> entities;

public:
    Game(Renderer* renderer, InputManager* inputManager);
    ~Game();
    void update(float deltaTime);
    void render();
    void addEntity(Entity* entity);
};

