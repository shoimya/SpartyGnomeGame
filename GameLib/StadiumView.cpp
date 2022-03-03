/**
 * @file StadiumView.cpp
 * @author SHOIMYA CHOWDHURY Shaojie Zhang, Haoxiang Zhang
 */
#include "pch.h"
#include "StadiumView.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
using namespace std;

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


void StadiumView::OnKeyUp(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
    case WXK_SPACE:
        //gnome -> SetyVelocity;
        break;
    }
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void StadiumView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mStadium.Update(elapsed);


    wxAutoBufferedPaintDC dc(this);
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
    auto size = GetClientSize();
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
//    mStadium.OnDraw(graphics, size.GetWidth(), size.GetHeight());
}

void StadiumView::OnTimer(wxTimerEvent& event)
{

}





