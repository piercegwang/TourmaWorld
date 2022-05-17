#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Game.hpp"
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

#define Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#define Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@

int main(int argc, char *argv[])
{
    Game *game;
    game = new Game();

    // std::cout << window.getRefreshRate() << std::endl;

    game->init("TourmaWorld v1.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
               1280, 720, 0);


    // std::vector<Entity> entities;

    // const float timeStep = 0.01f;
    // float accumulator = 0.0f;
    // float currentTime = utils::hireTimeInSeconds();

    game->initTicks();

    while (game->running())
    {

        // int startTicks = SDL_GetTicks64();

        // float newTime = utils::hireTimeInSeconds();
        // float frameTime = newTime - currentTime;

        // currentTime = newTime;

        // accumulator += frameTime;

        game->updateTime();

        while (game->tickHappened())
        {
            game->handleEvents();
            game->update();
            // accumulator -= timeStep;
            game->removeTick();
        }

        // const float alpha = accumulator / timeStep;
        game->calcAlpha();

        game->render();

        // int frameTicks = SDL_GetTicks64() - startTicks;

        // if (frameTicks < 1000 / window.getRefreshRate())
        // {
        //     SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
        // }
        game->delay();
    }

    game->clean();
    return 0;
}
