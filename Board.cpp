#include "Paddle.hpp"
#include "Board.hpp"
#include "Ball.hpp"
#include "Bricks.hpp"
#include "Game.hpp"
#include <vector>
#include <algorithm>



using std::vector;

#include <iostream> 
using std::cout;
using std::endl;

#include <SDL2/SDL.h>

Board::Board(const int height2, const int width2)
: paddle(*this)
, ball(*this)
, height(height2)
, width(width2)
, sizeOfBrickVec(18)
{
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 9; ++j){
            
            double x = 0;
            double y = 0;
            
                x = j * 64 + 16;
                y = i * 70 + 16;
            
            Bricks brick(*this, x, y);
            
            brickVec.push_back(brick);
            
        }
    }
}

void Board::update(SDL_Renderer * renderer, Input input)
{
    for(Bricks& brick : brickVec ){
        brick.renderUpdate(renderer);
    }
    ball.renderUpdate(renderer);
    
    paddle.renderUpdate(renderer, input);
    
    
    
    if(ballBrickCollision()){
    }
    else if(ballPaddleCollision()){
    }
    else if(ballBoardCollision()){
    }
    else{
    }


    
    
    
    
}

bool Board::ballPaddleCollision(){
    
    if((paddle.getXPos() <= (ball.getX()) || paddle.getXPos() <= (ball.getX() + 15)) && ball.getX() <= (paddle.getXPos() + 75)){
        if(((paddle.getYPos() <= ball.getY()) || (paddle.getYPos() <= ball.getY() + 15)) && ball.getY() <= (paddle.getYPos() + 7.5)){
            
            if((ball.getY() + 15  <= paddle.getYPos()) || ball.getY() >= (paddle.getYPos() +7.5)){
                ball.setYVel(-ball.getYVel());
                return true;
            }
            else{
                ball.setXVel(-ball.getXVel());
                return true;
            }
        }
    }
    return false;
}


bool Board::ballBrickCollision(){
    
    for(int i = 0; i <= brickVec.size(); ++i){
        
        if((brickVec[i].getX() <= (ball.getX()) || brickVec[i].getX() <= (ball.getX() + 15)) && ball.getX() <= (brickVec[i].getX() + 50)){
            if(((brickVec[i].getY() <= ball.getY()) || (brickVec[i].getY() <= ball.getY() + 15)) && ball.getY() <= (brickVec[i].getY() + 50)){
                
                if((ball.getY() + 15  <= brickVec[i].getY()) || ball.getY() >= (brickVec[i].getY() + 50)){
                    
                    
                    
                    
                    
                    ball.setYVel(-ball.getYVel());
                    brickVec.pop_back();
                    return true;
                }
                else{
                    brickVec.pop_back();
                    ball.setXVel(-ball.getXVel());
                    return true;
                }
            }
        }
    }
    return false;
}


bool Board::ballBoardCollision(){
    if((ball.getX()+15) > width || ball.getX() < 0){
        ball.setXVel(-ball.getXVel());
        return true;
    }
    else if(ball.getY() < 0){
        ball.setYVel(-ball.getYVel());
        return true;
    }
    return false;
}


vector<Bricks> Board::getBrickVec(){
    return brickVec;
}


int Board::getHeight() const {
    return height ;
}

int Board::getWidth() const {
    return width;
}





/*

Bricks & Board::operator[](const int i){
    if(i >= 0 & i < getBrickSize())
        return brickVec[i];
    else{
        abort();
    }
}



*/
