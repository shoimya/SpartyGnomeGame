/**
 * @file StadiumView.h
 * @author User, Shaojie Zhang
 *
 *
 */

#ifndef SPARTYGNOME_STADIUMVIEW_H
#define SPARTYGNOME_STADIUMVIEW_H

#include "Stadium.h"

/**
 * View class for our Game
 */
class StadiumView: public wxWindow  {
private:

    Stadium mStadium;

    wxTimer mTimer;
    wxStopWatch mStopWatch;

    long mTime = 0;

public:
    void Initialize(wxFrame* parent);

    void OnPaint(wxPaintEvent&);

    void OnKeyUp(wxKeyEvent& event);
};

#endif //SPARTYGNOME_STADIUMVIEW_H
