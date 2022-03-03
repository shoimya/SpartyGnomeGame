/**
 * @file StadiumView.cpp
 * @author User
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

}

void StadiumView::OnKeyUp(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
    case WXK_SPACE:
        return;
    }
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void StadiumView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
    auto size = GetClientSize();
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
    mStadium.OnDraw(graphics, size.GetWidth(), size.GetHeight());
}

