/**
 * @file StadiumView.h
 * @author User
 *
 *
 */

#ifndef SPARTYGNOME_STADIUMVIEW_H
#define SPARTYGNOME_STADIUMVIEW_H


/**
 * View class for our Game
 */
class StadiumView: public wxWindow  {
private:
    /// the game
    Stadium mStadium;
    /// The timer that allows for animation
    wxTimer mTimer;
    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    void OnPaint(wxPaintEvent& event);


    long mTime = 0;

public:
    void Initialize(wxFrame* parent);

    void OnKeyUp(wxKeyEvent& event);
};

#endif //SPARTYGNOME_STADIUMVIEW_H
