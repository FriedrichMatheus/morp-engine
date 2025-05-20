#include "renderer.h"


int main()
{
    Renderer renderer;
    InputManager inputManager;

    if(!renderer.init("My Game", 800, 600)) {
        return -1;
    }

    renderer.setInputManager(&inputManager);

    while (renderer.isRunning())
    {
        renderer.handleEvents();
        renderer.clear();
        //TODO: create update

        renderer.present();
    }

    renderer.destroy();
    return 0;
}