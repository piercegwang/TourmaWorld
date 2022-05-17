#ifndef MATH_H_
#define MATH_H_

#include<iostream>

class Vector2f
{
    public:
        float x, y;
        Vector2f()
            :x(0.0f), y(0.0f)
        {}

        Vector2f(float p_x=0, float p_y=0)
            :x(p_x), y(p_y)
        {}

        inline void print()
        {
            std::cout << x << ", " << y << std::endl;
        }

        inline Vector2f operator+(const Vector2f& v2) const {
            return Vector2f(x + v2.x, y + v2.y);
        }

        inline Vector2f operator-(concat Vector2f& v2) const {
            return Vector2f(x - v2.x, y - v2.y);
        }

        inline Vector2f operator*(const float scalar) const {
            return Vector2f(x*scalar, y*scalar);
        }
};

#endif // MATH_H_
