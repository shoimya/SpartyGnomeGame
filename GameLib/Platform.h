/**
 * @file Platform.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_PLATFORM_H
#define SPARTYGNOME_PLATFORM_H

#include "ItemPlatform.h"

class Platform : public ItemPlatform{
private:

public:
    Platform(Stadium *stadium, std::shared_ptr<Picture> picture);
    void XmlLoad(wxXmlNode* node) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    ~Platform();

};

#endif //SPARTYGNOME_PLATFORM_H
