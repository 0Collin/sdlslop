#include <iostream>
#include <SDL3/SDL.h>
#include "Stuff.hpp"

void Initialize();
void Cleanup();

bool progRunning = true;
SDL_Window* win = NULL;
// SDL_Renderer* renderMain = null;
SDL_Event test_event;
SDL_Renderer* renderMain = NULL;

void Initialize() {

const char* windowname = "Hi Brooke";
win = SDL_CreateWindow(windowname, 1280, 720, 0);
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL could not be initialized: " << SDL_GetError();
        progRunning = false;
        return;
	} else {
		std::cout << "SDL video system is ready to go\n";
	}
if (win == NULL) {
	std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    progRunning = false;
    return;
    }
renderMain = SDL_CreateRenderer(win, NULL, SDL_RENDERER_ACCELERATED);
}

void Cleanup(){
    SDL_DestroyWindow(win);
    SDL_Quit;
}


int main(int argc, char* argv[]){
    Initialize();
    SDL_Texture* tex = NULL;
    LoadImage("./assets/brooke.bmp", tex, renderMain);

while (progRunning) {
	SDL_RenderClear(renderMain);
	SDL_RenderTexture(renderMain, tex,  NULL, NULL);
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

