/**
 * @file Wall.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_WALL_H
#define SPARTYGNOME_WALL_H


#include "ItemPlatform.h"
#include "Visitor.h"

class Wall : public ItemPlatform{
private:
  Picture *mPicture;

public:
  Wall(Stadium *Stadium, Picture *picture);
  void Accept(Visitor *visitor) override{};
  ~Wall();


};

#endif //SPARTYGNOME_WALL_H
