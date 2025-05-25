#include "renderer.h"


Renderer::Renderer(): window(nullptr), renderer(nullptr), inputManager(nullptr), width(0), height(0), running(true) {}

Renderer::~Renderer() {
    destroy();
}

bool Renderer::init(const std::string& title, int w, int h) {
    width = w;
    height = h;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Failed to init SDL: %s", SDL_GetError());
    return false;
}

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, 
    SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if(!window) {
        SDL_Log("Erro on create window: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer) {
        SDL_Log("Erro on create renderer: %s", SDL_GetError());
        return false;
    }

    SDL_Log("Renderer inits with sucess!");
    return true;
}

InputManager* Renderer::getInputManager() {
    return inputManager;
}

SDL_Renderer* Renderer::getRenderer(){
    return renderer;
}

void Renderer::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            running = false;
            SDL_Log("Quit event executed!");
        }

        if(inputManager) {
            inputManager->updateEvent(event);
        }
    }
}

bool Renderer::isRunning() {
    return running;
}

void Renderer::setInputManager(InputManager* inputManager) {
    this->inputManager = inputManager;
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    if(SDL_RenderClear(renderer) < 0) {
        SDL_Log("Error on clear renderer: %s", SDL_GetError());
    }
}

void Renderer::draw(Texture* texture, int x, int h) {
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

void Renderer::destroy() {
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window) SDL_DestroyWindow(window);
}



