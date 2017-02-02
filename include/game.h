#ifndef GAME_H
#define GAME_H

#include <boost/scoped_ptr.hpp>

struct Sprite;
struct Graphics;

class Game {
public:
    Game();
    ~Game();
private:
   void eventLoop();
   void update();
   void draw(Graphics& graphics);

   boost::scoped_ptr<Sprite> sprite_;
};

#endif // GAME_H
