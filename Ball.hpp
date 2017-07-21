//
//  Ball.hpp
//  Breakout_Game
//
//  Created by Victor Guillemot on 05/07/2017.
//  Copyright © 2017 Victor Guillemot. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "Paddle.hpp"


class Board;

class Ball{
    
private:
    double width;
    double height;
    double xPos;
    double yPos;
    double xVel;
    double yVel;
   
    
    const Board& board;
    
public:
    Ball(Board& board);
    void renderUpdate(SDL_Renderer * renderer);
    
    
    void setXVel(double value);
    void setYVel(double value);
    
    void setXPos(double value);
    
    double getXVel();
    double getYVel();
    double getX();
    double getY();
    
};

#endif
