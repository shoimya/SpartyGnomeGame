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

/// The stadium
class Stadium {
private:
    void XmlItem(wxXmlNode* node);

    /// Directory containing the system images
    const std::wstring mImagesDirectory = L"data/images";

    /// Level directory
    const std::wstring mLevelDirectory = L"data/levels";

    /// Game area height in virtual pixels
    const static int Height = 1024;

    /// Game area height in virtual pixels
    double mScale = 0;

    /// The gnome
    Gnome* mGnome;

    /// The level item
    std::shared_ptr<Level> mLevel;

    /// All items list
    std::vector<Item*> mItems;

    /// The picture map
    std::map<std::wstring, std::shared_ptr<Picture>> mMapPictures;

//    int mLevelNum = 0;

    int mValue = 0;

    /// Game Mode
    int mGameMode;

    /// Time for game
    double mTime = 0;

public:
    /// The game modes
    enum GameMode {
        begin = 0, win = 1, progress = 2, loss = 3,
    };

    /**
     * Constructor
     */
    Stadium();

    /// Destructor
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

    void XmlPicture(wxXmlNode* node);

    void Load(int level);

    /**
     * Get the gnome function
     * @return The gnome of game
     */
    Gnome* GetGnome() { return mGnome; }

    /**
     * Set the level number
     * @param num The level number to set
     */
    void SetLevelNum(int num)
    {
        if (num>3) num = 3;
        mLevel->SetLevel(num);
    }

    /**
     * Get the level number
     * @return The level number to get
     */
    int GetLevelNum() { return mLevel->GetLevel(); }

    Item* HitTest(int x, int y);

    /**
     * Set the score value
     * @param value The value to set
     */
    void SetValue(int value) { mScoreBoard.SetScore(value); }

    /**
     * Get the score value
     * @return
     */
    int GetValue() const { return mScoreBoard.GetScore(); }

    /**
     * Set the game mode
     * @param num The game modes
     */
    void SetGameMode(int num) { mGameMode = num; }

    /**
     * Get the game modes
     * @return The game modes
     */
    int* GetGameMode() { return &mGameMode; }

    void AddScore(int value);

    int GetScore();

    /**
     * Get the time
     * @return The time of game
     */
    double GetTime() {return mTime;}

    /**
     * Set the time of game
     * @param time The time to set
     */
    void SetTime(double time) {mTime = time;}

    void TuitionUp();

    void Stop();

    void LevelComplete();

    /// The scoreboard class
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
    /**
     * The scoreboard item
     */
    ScoreBoard mScoreBoard = ScoreBoard(this);

};
#endif //SPARTYGNOME_STADIUM_H
