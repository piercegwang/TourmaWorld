#include "Engine.hpp"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Engine* Engine::s_Instance = nullptr;

Engine::Engine()
    :m_IsRunning(false)
{}

bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    std::cout << "test" << std::endl;

    m_Window = SDL_CreateWindow("TourmaWorld v0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                1280, 720, SDL_WINDOW_SHOWN);
    if (m_Window == nullptr) {
        SDL_Log("Failed to create Window: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED); //| SDL_RENDERER_PRESENTVSYNC);
    if (m_Window == nullptr) {
        SDL_Log("Failed to create Renderer: %s", SDL_GetError());
        return false;
    }

    return m_IsRunning = true;
}
bool Engine::Clean()
{
    return true;
}
void Engine::Quit()
{}

void Engine::Update()
{
    // SDL_Log("Updating");
}
void Engine::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
    SDL_RenderPresent(m_Renderer);
}
void Engine::Events()
{}
