#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "Tile.hpp"
#include "Player.hpp"

#define GRAVITY 0.8F

class Level
{
    public:
        Level(const std::string levelData[], const int levelHeight, const int tileSize);
        ~Level();
        void Run(SDL_Renderer* renderer);

    public:
        inline bool IsFinished() { return _isFinished; } 

    private:
        std::vector<Tile*> _tiles;
        Player* _player;

    private:
        float _worldShift;
        bool _isFinished;

    private:
        void handleCamera();
        void applyGravity();
        void handleHorizontalCollision();
        void handleVerticalCollision();
};

#endif