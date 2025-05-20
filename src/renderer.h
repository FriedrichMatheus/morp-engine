#pragma once
#include <SDL2/SDL_render.h>
#include "texture.h"
#include <string>
#include "input_manager.h"

class Renderer {
    SDL_Window* window;
    SDL_Renderer* renderer;
    InputManager* inputManager;
    int width;
    int height;
    bool running;
public:
    Renderer();
    ~Renderer();

    bool init(const std::string& title, int w, int h);
    bool isRunning();
    void setInputManager(InputManager* inputManager);
    void handleEvents();
    void clear();
    void draw(Texture* texture, int x, int y);
    void present();
    void destroy();
};