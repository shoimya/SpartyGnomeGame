/**
 * @file StadiumView.cpp
 * @author SHOIMYA CHOWDHURY Shaojie Zhang
 */
#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/stdpaths.h>

#include "StadiumView.h"
#include "ids.h"
// #include <wx/graphics.h>
using namespace std;

const double Frame = 30.0;
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

void StadiumView::AddMenus(wxFrame *mainFrame,wxMenuBar *menu, wxMenu* levelMenu)
{
    levelMenu->Append(IDM_ADDLEVEL0,L"Level0",L"load level0",wxITEM_CHECK);
    levelMenu->Append(IDM_ADDLEVEL1,L"Level1",L"load level1",wxITEM_CHECK);
    levelMenu->Append(IDM_ADDLEVEL2,L"Level2",L"load level2",wxITEM_CHECK);
    levelMenu->Append(IDM_ADDLEVEL3,L"Level3",L"load level3",wxITEM_CHECK);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level0,this,IDM_ADDLEVEL0);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level1,this,IDM_ADDLEVEL1);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level2,this,IDM_ADDLEVEL2);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level3,this,IDM_ADDLEVEL3);

}

void StadiumView::AddLevelMenuOption(wxFrame* mainFrame, wxMenu* menu, int id,std::wstring text, std::wstring help)
{
}

void StadiumView::Level0(wxCommandEvent& event)
{
    mStadium.Load(0);
}
void StadiumView::Level1(wxCommandEvent& event)
{
    mStadium.Load(1);
}
void StadiumView::Level2(wxCommandEvent& event)
{
    mStadium.Load(2);
}
void StadiumView::Level3(wxCommandEvent& event)
{
    mStadium.Load(3);
}


/**
* Timer event handler
* @param event Menu event
*/
void StadiumView::Timer(wxTimerEvent& event)
{
    Refresh();
}






