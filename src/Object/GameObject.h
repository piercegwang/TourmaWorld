#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "IObject.h"
#include "Transform.h"
#include "SDL2/SDL.h"
#include <string>

struct Properties
{
    Properties(std::string p_TextureID, int p_x, int p_y, int p_width, int p_height, SDL_RendererFlip p_Flip = SDL_FLIP_NONE) {
        X = p_x;
        X = p_y;
        Flip = p_Flip;
        Width = p_width;
        Height = p_height;
        TextureID = p_TextureID;
    }

    std::string TextureID;
    int Width, Height;
    float X, Y;
    SDL_RendererFlip Flip;
};

class GameObject : public IObject
{
public:
    GameObject(Properties* props): m_TextureID(props->TextureID),
        m_Width(props->Width), m_Height(props->Height), m_Flip(props->Flip) {
        m_Transform = new Transform(props->Y, props->Y);
    }

    virtual void Draw()=0;
    virtual void Clean()=0;
    virtual void Update(float dt)=0;

protected:
    Transform* m_Transform;
    int m_Width, m_Height;
    std::string m_TextureID;
    SDL_RendererFlip m_Flip;
};

#endif // GAMEOBJECT_H_
