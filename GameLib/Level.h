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

/// Level class for levels
class Level {
private:
    /// The level files
    std::wstring mFile;

    /// The stadium visit
    Stadium *mStadium;

    /// The level number
    int mLevelNum = level0;

public:
    /**
     * The level num
     */
    enum LevelNum{level0 = 0, level1 = 1, level2 = 2, level3 = 3};

    /**
     * Constructor
     * @param stadium The stadium we are visiting
     */
    Level(Stadium* stadium);
    /**
     * Xml load function
     * @param node  The node we are visiting
     * @return vector init position The init poistion for gnome
     */
    Vector XmlLoad(wxXmlNode *node);

    /**
     * The level 0 path
     * @return The leve 0 path
     */
    std::wstring Level0();

    /**
     * The level 1 path
     * @return The leve 1 path
     */
    std::wstring Level1();
    /**
     * The level 2 path
     * @return The leve 2 path
     */
    std::wstring Level2();
    /**
     * The level 3 path
     * @return The leve 3 path
     */
    std::wstring Level3();

    /**
     * Get the level number
     * @return The current level number
     */
    int GetLevel() const {return mLevelNum;}

    /**
     * Set the level number
     * @param level The level number to set
     */
    void SetLevel(int level){mLevelNum = level;}

    /// Destructor
    ~Level();


};

#endif //SPARTYGNOME_LEVEL_H
