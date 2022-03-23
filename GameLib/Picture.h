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

/// Picture class
class Picture {
private:
    /// Stadium
    Stadium *mStadium;

    /// Empty feature
    bool mEmpty = true;

    /// The image
    std::shared_ptr<wxImage> mImage = nullptr;

    /// The path
    std::wstring mFile = L"";

    /// The image position
    std::wstring mImagePos = L"";
public:
    /**
     * Constructor
     * @param stadium The stadium
     */
    Picture(Stadium* stadium);
    /// Destructor
    ~Picture();

    /**
     * Get graphics bitmap
     * @param graphics The graphics to draw
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

     /**
      * Set image position
      * @param pos The image position
      */
     void SetImagePos(std::wstring pos){mImagePos = pos;}

     /**
      * Get image position
      * @return Get the image position
      */
     std::wstring GetImagePos(){return mImagePos;}

     /**
      * Get the image
      * @return The image
      */
     std::shared_ptr<wxImage> GetImage(){return mImage;}
};

#endif //SPARTYGNOME_PICTURE_H
