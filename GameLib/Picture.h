/**
 * @file Picture.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_PICTURE_H
#define SPARTYGNOME_PICTURE_H

#include "Stadium.h"

class Picture {
private:
    Stadium *mStadium;

    std::wstring mFile;

    std::unique_ptr<wxImage> mImage;

public:
    Picture(Stadium* stadium);
    ~Picture();

    /**
     * Get graphics bitmap
     * @return wxGraphicsBitmap the bitmap of this Picture
     */
    wxGraphicsBitmap AsBitmap(std::shared_ptr<wxGraphicsContext>& graphics){
        return graphics->CreateBitmapFromImage(*mImage);}

    void SetImage(const std::wstring& file);

    int GetWidth(){return mImage->GetWidth();}

    int GetHeight(){return mImage->GetHeight();}
};

#endif //SPARTYGNOME_PICTURE_H
