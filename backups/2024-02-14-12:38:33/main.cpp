#include <iostream>
#include </usr/include/SDL3/SDL.h>

void Initialize();
void LoadImage();
void Cleanup();

SDL_Window* win = NULL;
SDL_Renderer* renderMain = NULL;
SDL_Texture* bitmapTex = NULL;
SDL_Surface* bitmapSurface = NULL;
bool progRunning = true;
SDL_Event test_event;

void Initialize(const char* windowname, SDL_Renderer &renderer){

	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL could not be initialized: " << SDL_GetError();
        progRunning = false;
        return;
	} else {
		std::cout << "SDL video system is ready to go\n";
	}
win = SDL_CreateWindow(windowname, 1280, 720, 0);
if (win == NULL) {
	std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    progRunning = false;
    return;
    }
}

void LoadImage(const char** image, SDL_Texture &texture, SDL_Renderer &renderer){
	SDL_Surface* surface = NULL;
    surface = SDL_LoadBMP(image);
if (!surface) {
std::cout << "Failed to load image: " << image << std::endl << SDL_GetError() << std::endl;
} else {
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
}
renderer = SDL_(CreateRenderer(win, NULL, SDL_RENDERER_ACCELERATED);
}

void Cleanup(){
	// Ideally for all of these to be thread safe, need to use atexit, but am dumb
	// std::atexit(SDL_DestroyWindow(win));
	SDL_DestroyWindow(win);
	std::atexit(SDL_Quit);
}

int main(int argc, char* argv[]){
    Initialize("Hi Brooke", renderMain);
    
SDL_FRect rectangle;
rectangle.x = 0.0;
rectangle.y = 0.0;
rectangle.w = 1280.0;
rectangle.h = 720.0;
while (progRunning) {
	SDL_RenderClear(renderMain);
	SDL_RenderTexture(renderMain, bitmapTex,  NULL, NULL);
	SDL_RenderPresent(renderMain);
while (SDL_PollEvent(&test_event)) {
	switch (test_event.type) {
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
    Cleanup();
	return 0;
}

