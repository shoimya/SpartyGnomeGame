/**
 * @file StadiumView.cpp
 * @author SHOIMYA CHOWDHURY Shaojie Zhang
 */
#include "pch.h"
#include "StadiumView.h"
#include <wx/dcbuffer.h>
#include <wx/stdpaths.h>
#include "ids.h"
// #include <wx/graphics.h>
using namespace std;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void StadiumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);

    // Determine where images are stored

//    wxStandardPaths& standardPaths = wxStandardPaths::Get();
//    std::wstring resourcesDir = standardPaths.GetResourcesDir().ToStdWstring();
//    mStadium.SetImagesDirectory(resourcesDir);

    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &StadiumView::OnPaint, this);
    Bind(wxEVT_TIMER,&StadiumView::Timer,this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::OnFileSaveas,this,wxID_SAVEAS);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &StadiumView::OnFileOpen, this, wxID_OPEN);


    mTimer.SetOwner(this);
    mStopWatch.Start();

    mStadium.Load("GameLib/data/levels/level1.xml");
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

    graphics->PushState();
    mStadium.OnDraw(graphics,size.GetWidth(),size.GetHeight());

//    mGame.OnDraw(graphics, size.GetWidth(), size.GetHeight());
//    auto size = GetClientSize();
//    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));
//    mStadium.OnDraw(graphics, size.GetWidth(), size.GetHeight());

    graphics->PopState();

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






