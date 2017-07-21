#include "Paddle.hpp"
#include "Game.hpp"
#include "Ball.hpp"
#include "Bricks.hpp"
#include "Board.hpp"
#include <SDL2/SDL.h>


Paddle::Paddle(Board& boardParameter)
: board(boardParameter)
{
    xPos = 250;
    yPos = 500;
    width = 75;
    height = 7.5;
    
}

void Paddle::renderUpdate(SDL_Renderer * renderer,Input input)
{
    SDL_SetRenderDrawColor(renderer, 255, 120, 80, 255);
    SDL_Rect rect;
    
    rect.x = xPos;
    rect.y = yPos;
    rect.w = width;
    rect.h = height;
    
    
    
    SDL_RenderFillRect(renderer, &rect);
    
    posUpdate(input);
}

void Paddle::posUpdate(Input input){
    
    if(input.getLeftBool() && xPos > 0){
        xPos -= 1.15;
    }
    else if(input.getRightBool() && xPos + 75 < board.getWidth()){
        xPos += 1.15;
    }
}

double Paddle::getXPos(){
    return xPos;
}

double Paddle::getYPos(){
    return yPos;
}

double Paddle::getWidth(){
    return width;
}

double Paddle::getHeight(){
    return height;
}
