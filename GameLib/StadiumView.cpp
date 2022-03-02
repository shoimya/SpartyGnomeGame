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


