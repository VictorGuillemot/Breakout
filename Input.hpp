//
//  Input.hpp
//  Breakout_Game
//
//  Created by Victor Guillemot on 07/07/2017.
//  Copyright © 2017 Victor Guillemot. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include <stdio.h>
#include <SDL2/SDL.h>


class Input{
    

private:
    bool isRightPushed;
    bool isLeftPushed;
    bool isUpPushed;
    bool isDownPushed;
    
public:
    Input();
    void setInputValue(SDL_Event key, bool value);
    bool getRightBool();
    bool getLeftBool();
    bool getUpBool();
    bool getDownBool();
    
};



#endif /* Input_hpp */
