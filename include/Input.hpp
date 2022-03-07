#ifndef INPUT_HPP
#define INPUT_HPP

#include <SDL2/SDL.h>

class Input
{
    public:
        inline static Input* Instance() { return _input = _input != nullptr ? _input : new Input(); }
        inline bool IsKeyDown(SDL_Scancode key) { return _keyboard[key] == 1; };
        inline SDL_Point GetCursor() { return _cursor; }
        
    public:
        bool Listen();

    private:
        Input();
        static Input* _input;
        const Uint8* _keyboard;
        SDL_Point _cursor;
};

#endif