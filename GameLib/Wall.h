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
    Picture *mPicture;
    
    double mWidth = 0.0;
    double mHeight = 0.0;

public:
    Wall(Stadium *Stadium, std::shared_ptr<Picture> picture);
    void Accept(Visitor *visitor) override{};
    ~Wall();
    
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double XOffSet, double yOffSet);
    
    void XmlLoad(wxXmlNode *node, int xPos);
    void SetHeight(double hei) {mHeight = hei;}
    void SetWidth(double wid) {mWidth = wid;}


};

#endif //SPARTYGNOME_WALL_H
