#include<SDL2/SDL.h>
#include<bits/stdc++.h>

const int SCREEN_WIDTH=1280;
const int SCREEN_HEIGHT=720;

int main(int argc, char *argv[]){
    // The window we'll be rendering to
    SDL_Window* window=NULL;

    // The surface contained by the window
    SDL_Surface* screenSurface=NULL;

    //Initialize SDL  初始化SDL視訊子系統
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        std::cout<<"SDL could not initialize! SDL_Error: "<<SDL_GetError()<<"\n";
        return 0;
    }

    

    //Create window  建立視窗
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

    //Get window surface
	screenSurface=SDL_GetWindowSurface(window);

	//Fill the surface green
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xff, 0x00));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Wait two seconds 延時2000毫秒
	SDL_Delay(2000);

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
    return 0;
}