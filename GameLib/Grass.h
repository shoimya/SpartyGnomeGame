/**
 * @file Grass.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_GRASS_H
#define SPARTYGNOME_GRASS_H

#include "ItemPlatform.h"
#include "Visitor.h"

class Grass : public ItemPlatform{
private:

public:
  Grass(Stadium *Stadium, std::shared_ptr<Picture> Picture);


//  void XmlLoad(wxXmlNode *node, int xPos);
  void Accept(Visitor *visitor) override {}
  ~Grass();

    

};

#endif //SPARTYGNOME_GRASS_H
