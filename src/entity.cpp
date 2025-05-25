#include "entity.h"

Entity::Entity(Renderer* renderer): renderer(renderer) {}
Entity::~Entity() {}

void Entity::render() {}
void Entity::update(float deltaTime) {}