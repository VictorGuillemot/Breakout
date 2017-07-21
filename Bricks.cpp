#include "Bricks.hpp"
#include "Board.hpp"

Bricks::Bricks(Board &board, double xPos, double yPos)
:board(board),height(50), width(50), xPos(xPos), yPos(yPos){
}

void Bricks::renderUpdate(SDL_Renderer * renderer){
    
    SDL_SetRenderDrawColor(renderer, 0, 165, 0, 255);
    
    SDL_Rect rect;
    rect.x = xPos;
    rect.y = yPos;
    rect.w = width;
    rect.h = height;
    
    SDL_RenderFillRect(renderer, &rect);
}


double Bricks::getX(){
    return xPos;
}


double Bricks::getY(){
    return yPos;
}


bool Bricks::getBool(){
    return isHere;
}

void Bricks::setBool(bool pleaseWork){
    isHere = pleaseWork;
}
