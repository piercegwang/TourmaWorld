#ifndef UTILS_H_
#define UTILS_H_

#include <SDL2/SDL.h>

namespace utils
{
    inline float hireTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }
}

#endif // UTILS_H_
