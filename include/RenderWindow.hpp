#ifndef RENDERWINDOW_H_
#define RENDERWINDOW_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.hpp"

class RenderWindow
{
    public:
        RenderWindow();
        void CreateWindow(const char* p_title, int p_x, int p_y, int p_w, int p_h, bool fullscreen);
        SDL_Texture *loadTexture(const char* p_filePath);

        int getRefreshRate();

        void cleanUp();
        void clear();
        void render(Entity& p_entity);
        void display();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer; // Uses OpenGL

};

#endif // RENDERWINDOW_H_
