/**
 * @file Stadium.h
 * @author SHOIMYA CHOWDHURY Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_STADIUM_H
#define SPARTYGNOME_STADIUM_H

#include <memory>
#include "Gnome.h"
#include "Item.h"
#include "Gnome.h"


class Stadium {
private:
    void XmlTile(wxXmlNode *node);

    /// Directory containing the system images
    std::wstring mImagesDirectory;

    /// Game area height in virtual pixels
    const static int Height = 1024;

    std::shared_ptr<Gnome> mGnome = nullptr;

    std::vector<std::shared_ptr<Item>> mItems;

public:
    enum GameMode {begin = 0, end = 1, progress = 2, loss = 3, win = 5};
    Stadium();
    virtual ~Stadium() = default;
    const std::wstring &GetImagesDirectory() {return mImagesDirectory;}

    void SetImageDirectory(const std::wstring& dir);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    void Update(double elapsed);
};

#endif //SPARTYGNOME_STADIUM_H
