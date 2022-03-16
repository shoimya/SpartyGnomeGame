/**
 * @file Wall.h
 * @author Haoxiang Zhang SHOIMYA CHOWDHURY
 *
 *
 */

#ifndef SPARTYGNOME_WALL_H
#define SPARTYGNOME_WALL_H


#include "ItemPlatform.h"
#include "Visitor.h"

class Wall : public ItemPlatform{
private:

public:
    Wall(Stadium *Stadium, std::shared_ptr<Picture> picture);
    ~Wall();
    
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void XmlLoad(wxXmlNode *node) override;

};

#endif //SPARTYGNOME_WALL_H
