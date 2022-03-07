#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL.h>
#include "Color.hpp"

class Sprite
{
    public:
        Sprite();
        Sprite(int w, int h, float x, float y, SDL_Color color = Color::Grey());
        SDL_Rect Rect();
        void DrawColor(SDL_Renderer* renderer);
        void DrawRect(SDL_Renderer* renderer);

    public:
        inline int GetWidth() { return Width; }
        inline int GetHeight() { return Height; }
        
    public:
        SDL_FPoint Position;
        SDL_Color Color;

    protected:
        int Width;
        int Height;
};

#endif