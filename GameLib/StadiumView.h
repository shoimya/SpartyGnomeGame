/**
 * @file StadiumView.h
 * @author SHOIMYA CHOWDHURY Shaojie Zhang
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

    wxTimer mTimer;
    wxStopWatch mStopWatch;

    Stadium mStadium;


    long mTime = 0;

    void OnPaint(wxPaintEvent& event);

    void OnKeyUp(wxKeyEvent& event);

    void OnTimer(wxTimerEvent& event);

public:
    void Initialize(wxFrame* parent);


};

#endif //SPARTYGNOME_STADIUMVIEW_H
