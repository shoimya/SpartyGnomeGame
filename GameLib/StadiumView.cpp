/**
 * @file StadiumView.cpp
 * @author SHOIMYA CHOWDHURY Shaojie Zhang
 */
#include "pch.h"
#include "StadiumView.h"
#include <wx/dcbuffer.h>
#include <wx/stdpaths.h>
// #include <wx/graphics.h>
#include "ids.h"
using namespace std;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void StadiumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);

    // Determine where images are stored

    wxStandardPaths& standardPaths = wxStandardPaths::Get();
    std::wstring resourcesDir = standardPaths.GetResourcesDir().ToStdWstring();
    mStadium.SetImagesDirectory(resourcesDir);

    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &StadiumView::OnPaint, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::OnFileSaveas,this,wxID_SAVEAS);
    // for the levels
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level1,this, IDM_ADDLEVEL1);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level2,this, IDM_ADDLEVEL2);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level3,this, IDM_ADDLEVEL3);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level0,this, IDM_ADDLEVEL0);
    
    mTimer.SetOwner(this);
    mStopWatch.Start();

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


    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;

    mStadium.Update(elapsed);


    auto size = GetClientSize();
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
//    mGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());
//    auto size = GetClientSize();
//    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
//    mStadium.OnDraw(graphics, size.GetWidth(), size.GetHeight());


}

/**
 * Menu handler for File SaveAs
 * @param event Mouse event
 */
void StadiumView::OnFileSaveas(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, _("Save Stadium file"), "", "",
            "Stadium Files (*.xml)|*.xml", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = saveFileDialog.GetPath();
    mStadium.Save(filename);
}


/**
* File>Open menu handler
* @param event Menu event
*/
void StadiumView::OnFileOpen(wxCommandEvent& event)
{
    wxFileDialog loadFileDialog(this, _("Load Stadium file"), "", "",
            "Stadium Files (*.xml)|*.xml", wxFD_OPEN);
    if (loadFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = loadFileDialog.GetPath();

    mStadium.Load(filename);
    Refresh();
}



/**
* Timer event handler
* @param event Menu event
*/
void StadiumView::Timer(wxTimerEvent& event)
{
    Refresh();
}

void StadiumView::Level0(wxCommandEvent& event)
{

}

void StadiumView::Level1(wxCommandEvent& event)
{

}

void StadiumView::Level2(wxCommandEvent& event)
{

}

void StadiumView::Level3(wxCommandEvent& event)
{

}




