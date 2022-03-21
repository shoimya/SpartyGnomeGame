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
    void XmlItem(wxXmlNode* node);

    /// Directory containing the system images
    const std::wstring mImagesDirectory = L"data/images";
    const std::wstring mLevelDirectory = L"data/levels";

    /// Game area height in virtual pixels
    const static int Height = 1024;

    /// Game area height in virtual pixels
    double mScale = 0;

    Gnome* mGnome;

    std::shared_ptr<Level> mLevel;

    std::vector<Item*> mItems;

    std::map<std::wstring, std::shared_ptr<Picture>> mMapPictures;

//    int mLevelNum = 0;

    int mValue = 0;

    /// Game Mode
    int mGameMode;

    /// Time for game
    double mTime = 0;

public:
    enum GameMode {
        begin = 0, win = 1, progress = 2, loss = 3,
    };

    /**
     * Constructor
     */
    Stadium();

    virtual ~Stadium() = default;

    /**
     * Get image directory
     * @return mImagesDirectory The image Directory
     */
    const std::wstring& GetImagesDirectory() { return mImagesDirectory; }

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, double width, double height);

    void Update(double elapsed);

    Item* CollisionTest(Item* item);

    void Save(const wxString& filename);

    void Load(const wxString& filename);

    void AddItem(Item* item);

    void Clear();

    void Delete(Item* item);

    void Reset();

    void XmlPicture(wxXmlNode* node);

    void Load(int level);

    Gnome* GetGnome() { return mGnome; }

    void SetLevelNum(int num)
    {
        if (num>3) num = 3;
        mLevel->SetLevel(num);
    }

    int GetLevelNum() { return mLevel->GetLevel(); }

    Item* HitTest(int x, int y);

    void SetValue(int value) { mScoreBoard.SetScore(value); }

    int GetValue() const { return mScoreBoard.GetScore(); }

    void SetGameMode(int num) { mGameMode = num; }

    int* GetGameMode() { return &mGameMode; }

    void AddScore(int value);

    int GetScore();

    double GetTime() {return mTime;}

    void SetTime(double time) {mTime = time;}

    void TuitionUp();

    void Stop();

    void LevelComplete();

    class ScoreBoard {
    public:
        ScoreBoard(Stadium* stadium)
                :mStadium(stadium) { }

        int GetScore() const { return mScore; }

        void SetScore(int score) { mScore = score; }

    private:
        Stadium* mStadium;

        int mScore = 0;
    };

private:
    ScoreBoard mScoreBoard = ScoreBoard(this);

};
#endif //SPARTYGNOME_STADIUM_H
