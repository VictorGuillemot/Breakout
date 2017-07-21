#include "Ball.hpp"
#include "Board.hpp"
#include "Paddle.hpp"

Ball::Ball(Board& boardParam)
:
board(boardParam),height(15),width(15),xPos(280), yPos(450),xVel(0.5),yVel(-0.5){
    
}

void Ball::renderUpdate(SDL_Renderer * renderer){
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_Rect rect;
    
    
    rect.x = xPos;
    rect.y = yPos;
    rect.h = height;
    rect.w = width;
    
    
    SDL_RenderFillRect(renderer, &rect);
    
    xPos += xVel;
    yPos += yVel;
    
}



void Ball::setXVel(double value){
    xVel = value;
}

void Ball::setYVel(double value){
    yVel = value;
}


double Ball::getXVel(){
    return xVel;
}

double Ball::getYVel(){
    return yVel;
}


double Ball::getX(){
    return xPos;
}


double Ball::getY(){
    return yPos;
}
