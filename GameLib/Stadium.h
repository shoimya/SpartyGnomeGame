/**
 * @file Stadium.h
 * @author SHOIMYA CHOWDHURY, Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_STADIUM_H
#define SPARTYGNOME_STADIUM_H

#include <memory>
#include <map>
#include "Gnome.h"
#include "Item.h"
#include "Picture.h"
#include "Level.h"


class Stadium {
private:
    void XmlItem(wxXmlNode *node);

    /// Directory containing the system images
    const std::wstring mImagesDirectory = L"data/images";
    const std::wstring mLevelDirectory = L"data/levels";

    /// Game area height in virtual pixels
    const static int Height = 1024;

    std::shared_ptr<Gnome> mGnome;

    std::shared_ptr<Level> mLevel = nullptr;

    std::vector<std::shared_ptr<Item>> mItems;

    std::vector<Picture*> mPictures;

    std::map<int ,Picture*> mMapPictures;

    double mScale;

public:
    enum GameMode {begin = 0, end = 1, progress = 2, loss = 3, win = 4};

    Stadium();
    virtual ~Stadium() = default;

    void SetImagesDirectory(const std::wstring &dir);

    const std::wstring &GetImagesDirectory() {return mImagesDirectory;}


    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, double width, double height);

    void Update(double elapsed);

    std::shared_ptr<Item> CollisionTest(Item* item);

    void Save(const wxString& filename);

    void Load(const wxString& filename);

    void AddItem(const std::shared_ptr<Item>& item);

    void AddPicture(Picture* picture);

    void Clear();

    void XmlPicture(wxXmlNode* node);

    void Load(int level);
};

#endif //SPARTYGNOME_STADIUM_H
