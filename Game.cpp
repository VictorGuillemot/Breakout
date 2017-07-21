#include "Game.hpp"
#include "Board.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Bricks.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include "Input.hpp"

using std::cout;
using std::endl;

Game::Game(const int height, const int width){
    
    windowHeight = height;
    windowWidth = width;
    
    window = nullptr;
    renderer = nullptr;
}

bool Game::windowCreation(){

    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow("Boomkin", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_RENDERER_ACCELERATED);
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    if(window == nullptr)
        return false;
    
    return true;
}

void Game::run(){
    
    bool running = true;
    
    Board board(windowHeight, windowWidth);
    
    Input input;

    while(running && (!board.getBrickVec().empty()) && !((board.ball.getY()+15) > board.getHeight())){
        SDL_Event event;
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        
        while(SDL_PollEvent(&event)){
            
            if(event.type == SDL_QUIT){
                running = false;
                break;
            }
            else if(event.type == SDL_KEYDOWN){
                
                input.setInputValue(event, true);
            }
            else if (event.type == SDL_KEYUP)
            {
                input.setInputValue(event, false);
            }
        }
       
        board.update(renderer, input);
        
        
        SDL_RenderPresent(renderer);
    }
}

void Game::shutdown(){
        
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


SDL_Renderer * Game::getRenderer(){
    return renderer;
}


SDL_Window * Game::getWindow(){
    return window;
}


const int Game::getHeight() const{
    return windowHeight;
}

const int Game::getWidth() const{
    return windowWidth;
}


