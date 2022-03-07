#ifndef MATH_HPP
#define MATH_HPP

class FVector2
{
    public:
        FVector2() { X = 0.0F; Y = 0.0F; }
        FVector2(float x, float y): X(x), Y(y) {}
        float X, Y;
};

#endif