#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

class Engine {
    private:
        Engine();
        bool m_IsRunning;

        SDL_Window* m_Window;
        SDL_Renderer* m_Renderer;
        static Engine* s_Instance;
    public:
        static Engine* GetInstance() {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
        }

        bool Init();
        bool Clean();
        void Quit();

        void Update();
        void Render();
        void Events();

        inline bool IsRunning() {return m_IsRunning;}
        inline SDL_Renderer* GetRenderer(){return m_Renderer;}
};

#endif // ENGINE_H_
