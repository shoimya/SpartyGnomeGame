/**
 * @file Level.h
 * @author Haoxiang Zhang
 *
 *
 */

#ifndef SPARTYGNOME_LEVEL_H
#define SPARTYGNOME_LEVEL_H

#include "Vector.h"

class Stadium;
class Item;

class Level {
private:
    std::wstring mFile;
    Stadium *mStadium;
    int mLevelNum = level0;

public:
    enum LevelNum{level0 = 0, level1 = 1, level2 = 2, level3 = 3};
    Level(Stadium* stadium);
    Vector XmlLoad(wxXmlNode *node);
    std::wstring Level0();
    std::wstring Level1();
    std::wstring Level2();
    std::wstring Level3();

    int GetLevel() const {return mLevelNum;}
    void SetLevel(int level){mLevelNum = level;}

    ~Level();


};

#endif //SPARTYGNOME_LEVEL_H
