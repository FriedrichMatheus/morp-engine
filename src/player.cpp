#include "entity.h"
#include <cmath>

typedef struct Vector2D
{
    int x,y;

    Vector2D normalize() const {
        float lenght = std::sqrt(x * x + y * y);

        if(lenght == 0) {
            return { 0, 0};
        }

        return { x / lenght, y / lenght };
    };
} Vector2D;

class Player: public Entity {

    InputManager* inputManager;
    SDL_Rect collider;
    Vector2D velocity = {0, 0};
    float speed = 200.0f;

public:
    Player(Renderer* renderer): Entity(renderer) {
        collider = {100, 100, 50, 50};
        inputManager = renderer->getInputManager();
    }

    void render() {
        SDL_SetRenderDrawColor(renderer->getRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawRect(renderer->getRenderer(), &collider);
    }

    void update(float deltaTime) {
        bool upKey = inputManager->isKeyPressed(SDLK_w);
        bool downKey = inputManager->isKeyPressed(SDLK_s);
        bool leftKey = inputManager->isKeyPressed(SDLK_a);
        bool rightKey = inputManager->isKeyPressed(SDLK_d);

        if(upKey) {
            collider.y -=  (speed * deltaTime);
            SDL_Log("Speed: %f", speed * deltaTime);
        }
        if(downKey) {
            collider.y +=  (speed * deltaTime);
            SDL_Log("Speed: %f", speed * deltaTime);
        }
        if(leftKey) {
            collider.x -=  (speed * deltaTime);
            SDL_Log("Speed: %f", speed * deltaTime);
        }
        if(rightKey) {
            collider.x +=  (speed * deltaTime);
            SDL_Log("Speed: %f", speed * deltaTime);
        }
        
    }

};