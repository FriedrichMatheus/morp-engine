#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>

class TextureManager {
    std::unordered_map<std::string, SDL_Texture*> textures;
    SDL_Renderer* renderer;

    TextureManager() : renderer(nullptr) {}
public:
    TextureManager(const TextureManager&) = delete;
    TextureManager& operator=(const TextureManager&) = delete;

    static TextureManager& getInstance() {
        static TextureManager instance;
        return instance;
    }

    void setRenderer(SDL_Renderer* r) {
        renderer = r;
    }

    SDL_Texture* load(std::string& id, std::string& path) {
        if(textures.count(id) > 0) return textures[id];
        
        SDL_Surface* surface = IMG_Load(path.c_str());

        if(!surface) {
            SDL_Log("Failed to load surface: %s", SDL_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if(!texture) {
            SDL_Log("Failed to create texture: %s", SDL_GetError());
            return nullptr;
        }

        textures[id] = texture;
        return texture;
    }

};