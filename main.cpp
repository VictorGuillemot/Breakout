#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {
    
    Game start(600,600);
    
    if(start.windowCreation())
        start.run();

    
    start.shutdown();
    
    return 0;
}
