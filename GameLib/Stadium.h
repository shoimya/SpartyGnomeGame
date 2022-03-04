/**
 * @file Stadium.h
 * @author SHOIMYA CHOWDHURY, Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_STADIUM_H
#define SPARTYGNOME_STADIUM_H

#include <memory>
#include "Gnome.h"
#include "Item.h"
#include "Picture.h"


class Stadium {
private:
    void XmlItem(wxXmlNode *node);

    /// Directory containing the system images
    std::wstring mImagesDirectory;

    /// Game area height in virtual pixels
    const static int Height = 1024;

    std::shared_ptr<Gnome> mGnome = nullptr;

    std::vector<std::shared_ptr<Item>> mItems;

    std::vector<std::shared_ptr<Picture>> mPictures;

public:
    enum GameMode {begin = 0, end = 1, progress = 2, loss = 3, win = 4};

    Stadium();
    virtual ~Stadium() = default;

    void SetImagesDirectory(const std::wstring &dir);

    const std::wstring &GetImagesDirectory() {return mImagesDirectory;}

    void SetImageDirectory(const std::wstring& dir);

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics);

    void Update(double elapsed);

    Item* CollisionTest(Item* item);

    void Save(const wxString& filename);

    void Load(const wxString& filename);

    void AddItem(std::shared_ptr<Item> item);

    void AddPicture(std::shared_ptr<Picture> picture);

    void Clear();
};

#endif //SPARTYGNOME_STADIUM_H
