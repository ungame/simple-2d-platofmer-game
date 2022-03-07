#include <iostream>
#include <string>

#include <SDL2/SDL.h>

#include "Settings.hpp"
#include "Input.hpp"
#include "Color.hpp"
#include "TileMap.hpp"
#include "Level.hpp"

int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl init failed: %s", SDL_GetError());

        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create window failed: %s", SDL_GetError());

        return EXIT_FAILURE;        
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == nullptr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "sdl create renderer failed: %s", SDL_GetError());

        return EXIT_FAILURE;        
    }

    std::string title = "";

    SDL_Color bg = Color::Black();

    const int levelHeight = sizeof(TileMap) / sizeof(TileMap[0]);
    Level* level = new Level(TileMap, levelHeight, TILE_SIZE);
    
    bool running = true;

    while(running)
    {
        running = Input::Instance()->Listen();

        SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
        SDL_RenderClear(renderer);

        title = WINDOW_TITLE + " | ";

        SDL_Point cursor = Input::Instance()->GetCursor();
        title += "MX=" + std::to_string(cursor.x) + " | ";
        title += "MY=" + std::to_string(cursor.y);

        SDL_SetWindowTitle(window, title.c_str());

        level->Run(renderer);

        if(level->IsFinished())
        {
            delete level;
            level = new Level(TileMap, levelHeight, TILE_SIZE);
        }


        SDL_RenderPresent(renderer);

        SDL_Delay(1000/60);
    }
    
    delete level;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return EXIT_SUCCESS;
}
