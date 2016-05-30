// code ripped from a texture loading example, ignore
#include <stdio.h>
#include <SDL2/SDL.h>

#define WIDTH 800
#define HEIGHT 600

int main (int argc, char *argv[]) {

  // variable declarations
  SDL_Window *win = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *img = NULL;
  int w, h; // texture width & height
  
  // Initialize SDL.
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
      return 1;
  
  // create the window and renderer
  // note that the renderer is accelerated
  win = SDL_CreateWindow("Cross compiling works!", 100, 100, WIDTH, HEIGHT, 0);
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  
  
  // main loop
  while (1) {
    
    // event handling
    SDL_Event e;
    if ( SDL_PollEvent(&e) ) {
      if (e.type == SDL_QUIT)
        break;
      else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
        break;
    } 
    
    // clear the screen
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // flip the backbuffer
    // this means that everything that we prepared behind the screens is actually shown
    SDL_RenderPresent(renderer);
    
  }
  
  SDL_DestroyTexture(img);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);
  
  return 0;
}