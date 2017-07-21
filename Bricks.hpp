#ifndef Bricks_hpp
#define Bricks_hpp


#include <stdio.h>
#include <SDL2/SDL.h>

#include <vector>
using std::vector;
#include <set>
using std::set;


class Board;

class Bricks{
    
private:
    double height;
    double width;
    const Board &board;
    double xPos;
    double yPos;
    
    bool isHere;
    
    
public:
    Bricks(Board &board, double xPlus, double yPlus);
    void renderUpdate(SDL_Renderer * renderer);
    
    double getX();
    double getY();
    bool getBool();
    
    void setBool(bool pleaseWork);
};

#endif /* Bricks_hpp */
