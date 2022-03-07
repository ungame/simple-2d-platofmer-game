#include <SDL2/SDL.h>

#include "Sprite.hpp"
#include "Color.hpp"

Sprite::Sprite()
{
    Position = { 0, 0 };
    Color = Color::Grey();

    Width = 0;
    Height = 0;
}

Sprite::Sprite(int w, int h, float x, float y, SDL_Color color)
{
    Width = w;
    Height = h;

    Position = { x, y };
    Color = color;
}

SDL_Rect Sprite::Rect()
{
    SDL_Rect rect = { (int)Position.x, (int)Position.y, Width, Height };

    return rect;
}

void Sprite::DrawColor(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, Color.r, Color.g, Color.b, Color.a);    
}

void Sprite::DrawRect(SDL_Renderer* renderer)
{
    SDL_Rect rect = Rect();
    DrawColor(renderer);
    SDL_RenderFillRect(renderer, &rect);
}
