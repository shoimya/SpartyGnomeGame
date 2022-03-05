/**
 * @file Picture.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_PICTURE_H
#define SPARTYGNOME_PICTURE_H

#include <memory>
#include <wx/graphics.h>

class Stadium;

class Picture {
private:
    Stadium *mStadium;

    bool mEmpty = true;

    std::shared_ptr<wxImage> mImage;

    std::wstring mFile;
public:
    Picture(Stadium* stadium);
    ~Picture();

    /**
     * Get graphics bitmap
     * @return wxGraphicsBitmap the bitmap of this Picture
     */
    wxGraphicsBitmap AsBitmap(std::shared_ptr<wxGraphicsContext>& graphics){ return graphics->CreateBitmapFromImage(*mImage);}

    /**
     * Set image for mImage
     * @param file The file string
     */
    void SetImage(const std::wstring& file);

    /**
     * Get width of image
     * @return Width of image
     */
    int GetWidth(){return mImage->GetWidth();}

    /**
     * Get height of image
     * @return Height of image
     */
    int GetHeight(){return mImage->GetHeight();}

    /**
     * Get filename
     * @return The image
     */
     bool Empty(){return mEmpty;}
};

#endif //SPARTYGNOME_PICTURE_H
