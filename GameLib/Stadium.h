/**
 * @file Stadium.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_STADIUM_H
#define SPARTYGNOME_STADIUM_H

#include "Gnome.h"

class Stadium {
private:
    void XmlTile(wxXmlNode *node);

    /// Directory containing the system images
    std::wstring mImagesDirectory;

    /// Game area height in virtual pixels
    const static int Height = 1024;

    std::shared_ptr<Gnome> mGnome;

public:
    Stadium();
    virtual ~Stadium() = default;
    const std::wstring &GetImagesDirectory() {return mImagesDirectory;}

    void SetImageDirectory(const std::wstring& dir);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //SPARTYGNOME_STADIUM_H
