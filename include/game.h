#ifndef GAME_H
#define GAME_H

struct SDL_Surface;

class Game {
public:
    Game();
    ~Game();
private:
   void eventLoop();
   void update();
   void draw();
   SDL_Surface* screen_;
};

#endif // GAME_H
