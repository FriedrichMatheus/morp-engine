#include "renderer.h"
#include "player.cpp"
#include "game.h"

int main()
{
    Renderer renderer;
    InputManager inputManager;
    Game game(&renderer);

    
    if(!renderer.init("My Game", 800, 600)) {
        return -1;
    }
    renderer.setInputManager(&inputManager);

    Player player(&renderer);
    game.addEntity(&player);

    Uint64 lastTick = SDL_GetPerformanceCounter();

    const int TARGET_FPS = 60;
    const float TARGET_FRAME_TIME = 1000.0f / TARGET_FPS;

    while (renderer.isRunning())
    {
        Uint64 nowTick = SDL_GetPerformanceCounter();

        float deltaTime = (nowTick - lastTick)/ (float) SDL_GetPerformanceFrequency();

        renderer.handleEvents();
        renderer.clear();
        
        game.update(deltaTime);
        
        game.render();
        renderer.present();
        
        float elapsedMS = (nowTick - lastTick) * 1000.0f / (float) SDL_GetPerformanceFrequency();
        if (elapsedMS < TARGET_FRAME_TIME) {
            SDL_Delay((Uint32)(TARGET_FRAME_TIME - elapsedMS));
        }
        lastTick = nowTick;
    }

    renderer.destroy();
    return 0;
}