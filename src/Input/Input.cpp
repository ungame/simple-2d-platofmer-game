#include <SDL2/SDL.h>
#include "Input.hpp"

Input* Input::_input = nullptr;

Input::Input()
{
    _keyboard = SDL_GetKeyboardState(nullptr);
    _cursor = { 0, 0 };
}

bool Input::Listen()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                return false;

            case SDL_MOUSEMOTION:
                _cursor.x = event.motion.x;
                _cursor.y = event.motion.y;
                break;

            case SDL_KEYDOWN:
            case SDL_KEYUP:
              _keyboard = SDL_GetKeyboardState(nullptr);  
              break;
        }
    }

    return true;
}