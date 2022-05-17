#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.hpp"

class Game {
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void initTicks();
        void updateTime();
        void update();
        bool tickHappened();
        void removeTick();
        void calcAlpha();
        void delay();
        void render();
        void clean();

        inline bool running() { return isRunning; }

    private:
        bool isRunning;
        RenderWindow window;
        SDL_Renderer *renderer;
        SDL_Event event;
        const float timeStep = 0.05f;
        float accumulator, currentTime, newTime, frameTime, alpha;
        int startTicks, frameTicks;
};

#endif // GAME_H_
