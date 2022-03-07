#include <SDL2/SDL.h>

#include "Player.hpp"
#include "Sprite.hpp"
#include "Math.hpp"
#include "Input.hpp"

Player::Player(int width, int height, float x, float y): Sprite(width, height, x, y)
{
    Direction = FVector2();
    Speed = FVector2(PLAYER_SPEED, 0);   
}

void Player::jump()
{
    Direction.Y = PLAYER_JUMP_FORCE;
}

void Player::Update()
{
    Direction.X = 0.0F;

    if(Input::Instance()->IsKeyDown(SDL_SCANCODE_LEFT))
        Direction.X = -1;
    
    if(Input::Instance()->IsKeyDown(SDL_SCANCODE_RIGHT))
        Direction.X = 1;
    
    if(Input::Instance()->IsKeyDown(SDL_SCANCODE_SPACE) && Direction.Y == 0)
        jump();
}