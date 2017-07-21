#include "Input.hpp"
#include <SDL2/SDL.h>

Input::Input()
:isRightPushed(false), isLeftPushed(false), isUpPushed(false), isDownPushed(false)
{
   
}


void Input::setInputValue(SDL_Event event, bool value){

    if(event.key.keysym.sym == SDLK_RIGHT){
        isRightPushed = value;
    }
    else if (event.key.keysym.sym == SDLK_LEFT){
        isLeftPushed = value;
    }
    else if (event.key.keysym.sym == SDLK_UP){
        isUpPushed = value;
    }
    else if (event.key.keysym.sym == SDLK_DOWN){
        isDownPushed = value;
    }
}

bool Input::getRightBool(){
    return isRightPushed;
}

bool Input::getLeftBool(){
    return isLeftPushed;
}

bool Input::getUpBool(){
    return isUpPushed;
}

bool Input::getDownBool(){
    return isDownPushed;
}

