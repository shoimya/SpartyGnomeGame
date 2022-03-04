/**
 * @file Grass.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_GRASS_H
#define SPARTYGNOME_GRASS_H

#include "Item.h"
#include "Visitor.h"

class Grass : public Item{
private:
  Picture* mPicture;

public:
  Grass(Stadium *Stadium, Picture *Picture);

  void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

  void Accept(Visitor *visitor) override {}
  ~Grass();

    

};

#endif //SPARTYGNOME_GRASS_H
