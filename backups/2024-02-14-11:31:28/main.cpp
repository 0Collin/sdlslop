#include <iostream>
#include </usr/include/SDL3/SDL.h>
#include <chrono>





void Cleanup(){
	// Ideally for all of these to be thread safe, need to use atexit, but am dumb
	// std::atexit(SDL_DestroyWindow(win));
	SDL_DestroyWindow(win);
	std::atexit(SDL_Quit);
}


int main(int argc, char* argv[]){

SDL_Window* win = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* bitmapTex = NULL;
SDL_Surface* bitmapSurface = NULL;
const char* image = NULL;
const char* windowname = "Hi Brooke";
bool progRunning = true;
SDL_Event test_event;
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL could not be initialized: " << SDL_GetError();
	} else {
		std::cout << "SDL video system is ready to go\n";
	}
win = SDL_CreateWindow(windowname, 1280, 720, 0);
if (win == NULL) {
	std::cout << "Could not create window: " << SDL_GetError() << std::endl;
} else {
	renderer = SDL_CreateRenderer(win, NULL, SDL_RENDERER_ACCELERATED);
	bitmapSurface = SDL_LoadBMP("./assets/brooke.bmp");
}
if (!bitmapSurface) {
std::cout << "Failed to load image: " << image << std::endl << SDL_GetError() << std::endl;
} else {
	bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
	SDL_DestroySurface(bitmapSurface);
}

SDL_FRect rectangle;
rectangle.x = 0.0;
rectangle.y = 0.0;
rectangle.w = 1280.0;
rectangle.h = 720.0;

while (progRunning)
{
	SDL_RenderClear(renderer);
	SDL_RenderTexture(renderer, bitmapTex,  NULL, NULL);
	SDL_RenderPresent(renderer);
while (SDL_PollEvent(&test_event)){
		switch (test_event.type){
case SDL_EVENT_MOUSE_MOTION:
	std::cout << "ur mouse moved" << std::endl;
	break;
case SDL_EVENT_QUIT:
std::cout << "time to quit" << std::endl;
	progRunning = false;
	break;
default:
break;
}
}
}
	return 0;
}

