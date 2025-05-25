#pragma once
#include <SDL2/SDL.h>
#include <string>

class Texture {
    SDL_Texture* texture;
    SDL_Renderer* renderer;
    int width;
    int height;
public:
    Texture(SDL_Renderer* renderer);
    ~Texture();
    Texture(SDL_Renderer* renderer, const std::string& path);

    bool loadFromFile(const std::string& path);
    void render(int x, int y);
    void render(int x, int y, int width, int height);
    void free();
};