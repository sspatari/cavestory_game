#ifndef GAME_H_
#define GAME_H_

#include <boost/scoped_ptr.hpp>

struct Player;
struct Graphics;

class Game {
public:
   Game();
   ~Game();

   static int kTileSize;
private:
   void eventLoop();
   void update(int elapsed_time_ms);
   void draw(Graphics& graphics);

   boost::scoped_ptr<Player> player_;
};

#endif // GAME_H_
