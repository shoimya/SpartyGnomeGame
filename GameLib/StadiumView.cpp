/**
 * @file StadiumView.cpp
 * @author User, Shaojie Zhang
 */
#include "pch.h"
#include "StadiumView.h"

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void StadiumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundColour(*wxWHITE);

    Bind(wxEVT_PAINT, &StadiumView::OnPaint, this);

}

void StadiumView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mStadium.Update(elapsed);
}


void StadiumView::OnKeyUp(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
    case WXK_SPACE:
        //gnome -> SetyVelocity;
        break;
    }
}






