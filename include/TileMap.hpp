#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <string>

const int MAP_HEIGHT = 10;
const int TILE_SIZE = 64;

const std::string TileMap[MAP_HEIGHT] = {
"                                       ",
"                                      T",
" TTTTTTTTTTTTTTTTT     TTTTTTTT  TTTTTT",
"   P                TT         T       ",
"                   TTTT                ",
"T            TTTTTTTTTTTT              ",
"         T T                   T       ",
"        TT                    TT       ",
"       TTTTTT               TTTTTTT     ",
"TTTTTTTTTTTTTTTTTT  TTTTTTTTTTTTTTTTTT ",
};

#endif