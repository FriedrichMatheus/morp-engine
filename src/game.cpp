
#include "game.h"


Game::Game(Renderer* renderer)
: renderer(renderer),  entities() {}

Game::~Game() {}

void Game::update(float deltaTime) {
    for(auto* entity : entities) {
        entity->update(deltaTime);
    }
}

void Game::render() {
    for(auto* entity : entities) {
        entity->render();
    }
}

void Game::addEntity(Entity* entity) {
    entities.push_back(entity);
}
