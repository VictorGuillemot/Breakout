#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>


#include "Paddle.hpp"
#include "Game.hpp"
#include "Ball.hpp"
#include "Bricks.hpp"
#include "Input.hpp"


class Board{
    
private:
    const int height;
    const int width;
    
    int sizeOfBrickVec;
    
    double xPlus;
    double yPlus;
    
    vector<Bricks> brickVec;
    
public:
    Board(const int height2, const int width2);
    
    Paddle paddle;
    Ball ball;
    
    void update(SDL_Renderer * renderer, Input input);
    
    bool ballPaddleCollision();
    bool ballBrickCollision();
    bool ballBoardCollision();
    
    
    vector<Bricks> getBrickVec();
    int getHeight() const ;
    int getWidth() const;
    
    Bricks & operator[](const int i);
    
};



#endif /* Board_hpp */
