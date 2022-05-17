#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.hpp"
#include "Utils.hpp"
#include "Entity.hpp"
#include "RenderWindow.hpp"

Game::Game()
{
    // RenderWindow window;
}

Game::~Game()
{}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed. SDL_ERROR: " << SDL_GetError() << std::endl;

    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "IMG init has failed. Error: " << SDL_GetError() << std::endl;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Substystems initialized" << std::endl;

        window.CreateWindow("TourmaWorld v1.0", xpos, ypos, width, height, fullscreen);

        isRunning = true;
    } else {
        isRunning = false;
    }
}

void Game::handleEvents()
{

    SDL_PollEvent(&event);
    switch(event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }

}

void Game::initTicks()
{
    accumulator = 0.0f;
    currentTime = utils::hireTimeInSeconds();
}

void Game::updateTime()
{
    startTicks = SDL_GetTicks64();
    newTime = utils::hireTimeInSeconds();
    frameTime = newTime - currentTime;

    currentTime = newTime;

    accumulator += frameTime;
}

void Game::update()
{}

bool Game::tickHappened()
{
    return accumulator >= timeStep;
}

void Game::removeTick()
{
    accumulator -= timeStep;
}

void Game::render()
{
    window.clear();
    // Add stuff to render

    SDL_Texture* grassTexture = window.loadTexture("../res/textures/grass.png");

    Entity platform0(Vector2f(100, 100), grassTexture);

    window.render(platform0);

    window.display();
}

void Game::calcAlpha()
{
    // is this necessary?
    alpha = accumulator / timeStep;
}

void Game::delay()
{
    frameTicks = SDL_GetTicks64() - startTicks;

    if (frameTicks < 1000 / window.getRefreshRate())
    {
        SDL_Delay(1000/window.getRefreshRate() - frameTicks);
    }
}

void Game::clean()
{
    window.cleanUp();
    SDL_Quit();
    std::cout << "Game cleaned." << std::endl;
}
