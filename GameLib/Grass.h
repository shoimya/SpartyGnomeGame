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

/// Base class for Grass type platform
class Grass : public ItemPlatform{
private:

public:
    ///constructor
  Grass(Stadium *Stadium, std::shared_ptr<Picture> Picture);


    //  void XmlLoad(wxXmlNode *node, int xPos);
  void Accept(Visitor *visitor) override {}
  
    ///destructor
  ~Grass();

    

};

#endif //SPARTYGNOME_GRASS_H
