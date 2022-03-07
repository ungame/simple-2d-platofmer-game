#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <string>
#include "TileMap.hpp"

const std::string WINDOW_TITLE = "2D PLATFORMER";
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = (sizeof(TileMap) / sizeof(TileMap[0])) * TILE_SIZE;

#endif