#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "Vector2D.h"

class Transform
{
public:
    float x, y;

public:
    Transform(float p_x=0, float p_y=0):x(p_x), y(p_y) {}
    void Log(std::string msg = "") {
        std::cout << msg << "(X Y) = (" << x << " " << y << ")" << std::endl;
    }

public:
    inline void TranslateX(float p_x) {x += p_x;}
    inline void TranslateY(float p_y) {y += p_y;}
    inline void Translate(Vector2D v) {x += v.x; y += v.y;}

};

#endif // TRANSFORM_H_
