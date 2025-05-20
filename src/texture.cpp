#include <SDL2/SDL_image.h>
#include <string>
#include "texture.h"

Texture::Texture(SDL_Renderer* renderer) 
: texture(nullptr), renderer(renderer), width(0), height(0) {}

Texture::Texture(SDL_Renderer* renderer, const std::string& path) 
: texture(nullptr), renderer(renderer), width(0), height(0) {
    loadFromFile(path);
}

Texture::~Texture() {
    free();
}

bool Texture::loadFromFile(const std::string& path) {
    free();

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if(!loadedSurface) {
        SDL_Log("Error on load image %s: %s", path.c_str(), IMG_GetError());
        return false;
    }

    texture = SDL_CreateTextureFromSurface(this->renderer, loadedSurface);

    if(!texture) {
        SDL_Log("Error on load texture %s: %s", path.c_str(), SDL_GetError());
        SDL_FreeSurface(loadedSurface);

        return false;
    }

    width = loadedSurface->w;
    height = loadedSurface->h; 

    SDL_FreeSurface(loadedSurface);
    return true;
}

void Texture::render(int x, int y) {
    SDL_Rect dst = {x, y, width, height};

    SDL_RenderCopy(renderer, texture, nullptr, &dst);
}

void Texture::render(int x, int y, int w, int h) {
    SDL_Rect dst = {x, y, w, h};

    SDL_RenderCopy(renderer, texture, nullptr, &dst);
}

void Texture::free() {
    if(!texture) return;
    SDL_DestroyTexture(texture);
    texture = nullptr;
    width = 0;
    height = 0;
}