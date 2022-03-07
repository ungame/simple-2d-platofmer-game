#include <iostream>
#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "Level.hpp"
#include "Tile.hpp"
#include "Player.hpp"
#include "Settings.hpp"

Level::Level(const std::string levelData[], const int levelHeight, const int tileSize)
{
    SDL_Log("Level: Height=%d, TileSize=%d", levelHeight, tileSize);

    _worldShift = 0.0F;
    _isFinished = false;

    for(int row = 0; row < levelHeight; row++)
    {
        int cols = levelData[row].length();

        for(int col = 0; col < cols; col++)
        {
            char cell = levelData[row][col];
            float x = tileSize * col;
            float y = tileSize * row;

            if(cell == 'T')
            {
                Tile* tile = new Tile(tileSize, tileSize, x, y);
                _tiles.push_back(tile);
            }

            if(cell == 'P')
            {
                _player = new Player(tileSize / 2, tileSize / 2, x, y);
                _player->Color = Color::Red();
            }
        }
    }
}

void Level::handleCamera()
{
    if(_player->Direction.X > 0 && _player->Position.x > 1000)
    {
        _player->Speed.X = 0;
        _worldShift = -PLAYER_SPEED;
    }
    else if(_player->Direction.X < 0 && _player->Position.x < 200)
    {
        _player->Speed.X = 0;
        _worldShift = PLAYER_SPEED;
    }
    else
    {
        _player->Speed.X = PLAYER_SPEED;
        _worldShift = 0;
    }
}

void Level::applyGravity()
{
    _player->Direction.Y += GRAVITY;
    _player->Position.y += _player->Direction.Y;
}

void Level::handleHorizontalCollision()
{
    _player->Position.x += _player->Direction.X * _player->Speed.X;

    SDL_Rect playerRect = _player->Rect();

    for(Tile* tile: _tiles)
    {
        SDL_Rect tileRect = tile->Rect();

        if(SDL_HasIntersection(&playerRect, &tileRect))
        {
            if(_player->Direction.X > 0)
            {
                int leftSide = tileRect.x - _player->GetWidth();
                _player->Position.x = leftSide;
            }
            else if(_player->Direction.X < 0)
            {
                int rightSide = tileRect.x + tileRect.w;
                _player->Position.x = rightSide;
            }

            _player->Direction.X = 0;
        }
    }
}

void Level::handleVerticalCollision()
{
    applyGravity();

    SDL_Rect playerRect = _player->Rect();

    for(Tile* tile: _tiles)
    {
        SDL_Rect tileRect = tile->Rect();

        if(SDL_HasIntersection(&playerRect, &tileRect))
        {
            if(_player->Direction.Y > 0)
            {
                int bottomSide = tileRect.y - _player->GetHeight();
                _player->Position.y = bottomSide;
            }
            else if(_player->Direction.Y < 0)
            {
                int topSide = tileRect.y + tileRect.h;
                _player->Position.y = topSide;
            }

            _player->Direction.Y = 0;
        }
    }

    if(_player->Position.y > SCREEN_HEIGHT)
        _isFinished = true;
}

void Level::Run(SDL_Renderer* renderer)
{
    _player->Update();

    handleHorizontalCollision();
    handleVerticalCollision();
    handleCamera();

    for(Tile* tile: _tiles)
    {
        tile->DrawRect(renderer);
        tile->Update(_worldShift);
    }

    _player->Draw(renderer);
}

Level::~Level()
{
    _tiles.clear();
    delete _player;
    SDL_Log("Level destroyed.");
}