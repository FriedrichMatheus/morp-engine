#include "entity.h"

class Player: public Entity {
public:
    Player(InputManager* inputManager): Entity(inputManager) {}

    void render() {
    }

    void update(float deltaTime) {
    }

};