#include <SDL2/SDL.h>
// #include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>
// #include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <a.h>

const int SCREEN_WIDTH=1280;
const int SCREEN_HEIGHT=720;

void GameLoop(){
    ;
}

int main(int argc, char *argv[]){
    // The window we'll be rendering to
    SDL_Window* window=NULL;

    // The surface contained by the window
    SDL_Surface* screen=NULL;

    // Initialize SDL  初始化SDL視訊子系統
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::cout<<"SDL could not initialize! SDL_Error: "<<SDL_GetError()<<"\n";
        return 0;
    }
    // IMG_Init(IMG_INIT_PNG);

    // 
    SDL_Renderer *renderer=SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer==nullptr){
        SDL_DestroyWindow(window);
        return 1;
    }

    
    SDL_Texture* texture=SDL_CreateTextureFromSurface(renderer, screen);
    if (texture == NULL){
        return 0;
    }
    SDL_FreeSurface(screen);
    

    // Create window  建立視窗
	window = SDL_CreateWindow(
        "Hello SDL",            // 視窗標題
		SDL_WINDOWPOS_UNDEFINED,// 視窗位置設定
        SDL_WINDOWPOS_UNDEFINED, 
        SCREEN_WIDTH,           // 視窗的寬度
        SCREEN_HEIGHT,          // 視窗的高度
        SDL_WINDOW_SHOWN        // 顯示視窗
    );

    if(window==NULL){
		std::cout<<"Window could not be created! SDL_Error: "<<SDL_GetError()<<"\n";
		return 0;
	}

    GameLoop();

    // Clear the renderer with the current drawing color
    SDL_RenderClear(renderer);
    
    // Create a rectangle
    SDL_Rect rect = { 100, 100, 200, 200 };
    
    // Draw the rectangle on the renderer
    SDL_RenderFillRect(renderer, &rect);
    
    // Update the renderer
    SDL_RenderPresent(renderer);
    
    // Wait for 5 seconds
    SDL_Delay(5000);
    
    // Clean up
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}