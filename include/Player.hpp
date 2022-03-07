#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Sprite.hpp"
#include "Math.hpp"

#define PLAYER_SPEED 8.0F
#define PLAYER_JUMP_FORCE -16.0F

class Player: public Sprite
{
    public:
        Player(int width, int height, float x, float y);
        FVector2 Direction;
        FVector2 Speed;

    public:
        void Update();

    public:    
        inline void Draw(SDL_Renderer* renderer) { DrawRect(renderer); }

    private:
        void jump();
};

#endif