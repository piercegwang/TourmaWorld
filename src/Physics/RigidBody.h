#ifndef RIGIDBODY_H_
#define RIGIDBODY_H_

#include "Vector2D.h"

#define UNI_MASS 1.0f
#define GRAVITY 9.8f

#define FORWARD 1
#define BACKWARD -1

#define UPWARD -1
#define DOWNWARD 1

class RigidBody
{
public:
    RigidBody() {
        m_Mass = UNI_MASS;
        m_Gravity = GRAVITY;
    }

    /* Setter and getter */
    inline void SetMass(float mass) {m_Mass = mass;}

    inline void SetGravity(float gravity) {m_Gravity = gravity;}

    inline void ApplyForce(Vector2D F) {m_Force = F;}
    inline void ApplyForceX(float Fx) {m_Force.x = Fx;}
    inline void ApplyForceY(float Fy) {m_Force.y = Fy;}
    inline void UnSetForce(){m_Force = Vector2D(0, 0);}


    // Friction
    inline void ApplyFriction(Vector2D Fr) {m_Friction = Fr;}
    inline void UnSetFriction(){m_Friction = Vector2D(0, 0);}

    // Getters
    inline float GetMass() {return m_Mass;}
    inline Vector2D Position(){return m_Position;}
    inline Vector2D Velocity(){return m_Velocity;}
    inline Vector2D Acceleration() {return m_Acceleration;}

    // Update Methods
    inline void Update(float dt) {
        m_Acceleration.x = (m_Force.x + m_Friction.x)/m_Mass;
        m_Acceleration.y = m_Gravity + m_Force.y/m_Mass;
        m_Velocity = m_Acceleration*dt;
        m_Position = m_Velocity*dt;
    }

private:
    float m_Mass;
    float m_Gravity;

    Vector2D m_Force;
    Vector2D m_Friction;

    Vector2D m_Position;
    Vector2D m_Velocity;
    Vector2D m_Acceleration;
};

#endif // RIGIDBODY_H_
