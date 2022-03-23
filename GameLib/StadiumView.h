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

    /// The stadium
    Stadium mStadium;

    /// Timer for game
    wxTimer mTimer;

    /// The stopwatch for game
    wxStopWatch mStopWatch;

    /// Paint function for game
    void OnPaint(wxPaintEvent& event);

    /// The time
    long mTime = 0;

public:
    void Initialize(wxFrame* parent);

    void OnFileSaveas(wxCommandEvent& event);

    void OnFileOpen(wxCommandEvent& event);

    void Timer(wxTimerEvent& event);

    void Level0(wxCommandEvent& event);

    void Level1(wxCommandEvent& event);

    void Level2(wxCommandEvent& event);

    void Level3(wxCommandEvent& event);

    void AddMenus(wxFrame* mainFrame, wxMenuBar* menu, wxMenu* levelMenu);

    void OnKeyDown(wxKeyEvent& event);

    void OnKeyUp(wxKeyEvent& event);

    /**
     * Stop function
     */
    void Stop() {mTimer.Stop();}
};

#endif //SPARTYGNOME_STADIUMVIEW_H
