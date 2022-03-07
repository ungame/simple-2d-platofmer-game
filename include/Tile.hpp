#ifndef TILE_HPP
#define TILE_HPP

#include "Sprite.hpp"

class Tile: public Sprite
{
    public:
        Tile(int width, int height, float x, float y): Sprite(width, height, x, y) {}

    public:
        inline void Update(float xShift) { Position.x += xShift; }
};

#endif
