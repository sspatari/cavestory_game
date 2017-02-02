/*  Game class
    Holds all information dealing with game loop
*/
#include <SDL/SDL.h>
#include "game.h"

Game::Game() {
   SDL_Init(SDL_INIT_EVERYTHING);
   eventLoop();
}

Game::~Game() {
   SDL_Quit();
}

void Game::eventLoop() {
   bool running  = true;
   while (running) {
      // THis loop lasts 1/60th of a second
      //                   1000/60ths ms
      // update();
      // draw();
      SDL_Delay(1000/*ms*/ / 60/*fps*/ /*ms*/);
   }
   // while (running) ~ 60 Hz
   //    Handle input. Handle timer callbacks.
   //
   //    update(). Move the player. Move projectiles. Check collisions
   //    draw()   draw everything!
}
