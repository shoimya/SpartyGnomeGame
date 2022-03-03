/**
 * @file StadiumView.h
 * @author SHOIMYA CHOWDHURY Shaojie Zhang
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

    wxTimer mTimer;
    wxStopWatch mStopWatch;


    long mTime = 0;

public:
    void Initialize(wxFrame* parent);

    void OnKeyUp(wxKeyEvent& event);
};

#endif //SPARTYGNOME_STADIUMVIEW_H
