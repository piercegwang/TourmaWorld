#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include <iostream>
#include <string>

class Vector2D
{
public:
    float x, y;


public:
Vector2D(float p_x=0, float p_y=0): x(p_x), y(p_y) {}

public:
    // addition +
    inline Vector2D operator+(const Vector2D& v2) const {
        return Vector2D(x + v2.x, y + v2.y);
    }

    // difference -
    inline Vector2D operator-(const Vector2D& v2) const {
        return Vector2D(x - v2.x, y - v2.y);
    }

    // multiplication *
    inline Vector2D operator*(const float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // division /
    inline Vector2D operator/(const float scalar) const {
        return Vector2D(x / scalar, y / scalar);
    }

    void Log(std::string msg = "") {
        std::cout << msg << "(X Y) = (" << x << " " << y << ")" << std::endl;
    }
};

#endif // VECTOR2D_H_
