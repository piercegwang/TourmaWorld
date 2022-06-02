#include "Engine.h"
#include "TextureManager.h"
#include "Vector2D.h"
#include "Transform.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"
#include "Input.h"
#include "Timer.h"

Engine* Engine::s_Instance = nullptr;
Player *user = nullptr;

Engine::Engine()
    :m_IsRunning(false)
{}

bool Engine::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }

    m_Window = SDL_CreateWindow("TourmaWorld v0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                1280, 720, SDL_WINDOW_SHOWN);
    if (m_Window == 0) {
        SDL_Log("Failed to create Window: %s", SDL_GetError());
        return false;
    }

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //| SDL_RENDERER_PRESENTVSYNC);
    if (m_Renderer == 0) {
        SDL_Log("Failed to create Renderer: %s", SDL_GetError());
        return false;
    }

    TextureManager::GetInstance()->Load("player", "../assets/textures/peter.png");
    TextureManager::GetInstance()->Load("player_run", "../assets/textures/peter.png");
    TextureManager::GetInstance()->Load("grass", "../assets/textures/grass.png");

    user = new Player(new Properties("player", 100, 200, 32, 32));

    return (m_IsRunning = true);
}
bool Engine::Clean()
{
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    IMG_Quit();
    SDL_Quit();

    return true;
}
void Engine::Quit()
{
    m_IsRunning = false;
}

void Engine::Update()
{
    float dt = Timer::GetInstance()->GetDeltaTime();
    // SDL_Log("Updating");
    user->Update(dt);
}
void Engine::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 124, 218, 254, 255);
    SDL_RenderClear(m_Renderer);

    user->Draw();
    TextureManager::GetInstance()->Draw("grass", 300, 300, 128, 128);
    SDL_RenderPresent(m_Renderer);
}
void Engine::Events()
{
    Input::GetInstance()->Listen();
}
