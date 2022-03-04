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

class Level {
private:
    std::wstring mFile;
    Stadium *mStadium;

public:
    Level(Stadium* stadium);
    Vector XmlLoad(wxXmlNode *node);
    std::wstring Level0();
    std::wstring Level1();
    std::wstring Level2();
    std::wstring Level3();
    ~Level();


};

#endif //SPARTYGNOME_LEVEL_H
