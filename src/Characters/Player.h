#ifndef PLAYER_H_
#define PLAYER_H_

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"

class Player: public Character
{
public:
    Player(Properties* props);

    virtual void Draw();
    virtual void Clean();
    virtual void Update(float dt);

private:
    Animation* m_Animation;
    RigidBody* m_RigidBody;
};

#endif // PLAYER_H_
