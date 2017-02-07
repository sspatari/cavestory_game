#ifndef PLAYER_H_
#define PLAYER_H_

#include <boost/shared_ptr.hpp>
#include <map>
#include <sprite.h>

struct Graphics;

struct Player {
   Player(Graphics& graphic, int x, int y);

   void update(int elapsed_time_ms);
   void draw(Graphics& graphics);

   void startMovingLeft();
   void startMovingRight();
   void stopMoving();

private:
   enum MotionType {
      STANDING,
      WALKING
   };
   enum HorizontalFacing {
      LEFT,
      RIGHT
   };

   struct SpriteState {
      SpriteState(MotionType motion_type=STANDING,
                  HorizontalFacing horizontalfacing=LEFT) :
         motion_type(motion_type),
         horizontalfacing(horizontalfacing) {}

      MotionType motion_type;
      HorizontalFacing horizontalfacing;
   };
   friend bool operator<(const SpriteState& a, const SpriteState& b);
   void initializeSprites(Graphics& graphics);

   SpriteState getSpriteState();
   int x_, y_;
   float velocity_x_;
   float acceleration_x_;
   HorizontalFacing horizontalfacing_;

   std::map<SpriteState, boost::shared_ptr<Sprite> > sprites_;
};

#endif // PLAYER_H_
