#ifndef STUFF_HPP
#define STUFF_HPP

#include <SDL3/SDL.h>
#include <iostream>

void LoadImage(const char* image, SDL_Texture*& texture, SDL_Renderer* renderer){
SDL_Surface* surface = NULL;
surface = SDL_LoadBMP(image);
if (!surface) {
    std::cout << "Failed to load image: " << image << std::endl << SDL_GetError() << std::endl;
} else {
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    std::cout << "Successfully loaded image: " << image << std::endl;
    SDL_DestroySurface(surface);
}
}
    

void CreateRect(){
// Placeholder
}


#endif
