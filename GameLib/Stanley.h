/**
 * @file Stanley.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_STANLEY_H
#define SPARTYGNOME_STANLEY_H

#include "Item.h"
#include "Visitor.h"
#include "VisitorStanley.h"

class Stanley : public Item{
private:
    Picture *picture;

public:
    Stanley(Stadium* stadium, std::shared_ptr<Picture> picture);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    ~Stanley();

    bool CollisionTest(Item* item);

    void XmlLoad(wxXmlNode* node);

    void Accept(Visitor* visitor) override {visitor->VisitStanley(this);}
};

#endif //SPARTYGNOME_STANLEY_H
