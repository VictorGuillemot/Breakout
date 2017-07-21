#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>

using std::string;

class Game{
    
private:
    int windowHeight;
    int windowWidth;
    
    SDL_Window * window;
    SDL_Renderer * renderer;
    
public:
    Game(const int windowHeight, const int windowWidth);
    
    bool windowCreation();
    
    
    void run();
    void shutdown();
    
    SDL_Renderer * getRenderer();
    SDL_Window * getWindow();
    const int getHeight() const;
    const int getWidth() const;
};

#endif /* Game_hpp */
