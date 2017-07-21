#ifndef Paddle_hpp
#define Paddle_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Game.hpp"
#include <SDL2/SDL.h>
#include "Input.hpp"

class Board;

class Paddle{
    
    double xPos;
    double yPos;
    
    double width;
    double height;
    
    const Board& board;
    
public:
    Paddle(Board& board);
    void renderUpdate(SDL_Renderer * renderer, Input input);
    
    void posUpdate(Input input);

    
    double getXPos();
    double getYPos();
    
    double getWidth();
    double getHeight();
};


#endif
