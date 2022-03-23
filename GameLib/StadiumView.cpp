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

/// THe frame of game
const double Frame = 2;
/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.050;
/**
 * Initialize the stadium view class.
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
    Bind(wxEVT_KEY_DOWN,&StadiumView::OnKeyDown,this);
    Bind(wxEVT_KEY_UP, &StadiumView::OnKeyUp, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::OnFileSaveas,this,wxID_SAVEAS);
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &StadiumView::OnFileOpen, this, wxID_OPEN);

    mTimer.SetOwner(this);
    mStadium.Load("data/levels/level1.xml");
    mStadium.SetLevelNum(1);
    mTimer.Start(Frame);
    mStopWatch.Start();

}


/**
 * The key down event function
 * @param event Key pressed event
 */
void StadiumView::OnKeyDown(wxKeyEvent& event)
{
    auto gnome = mStadium.GetGnome();
    switch (event.GetKeyCode())
    {
    case WXK_SPACE:
        gnome->MovingUp();
        break;

    case WXK_LEFT:
        gnome->MovingLeft();
        break;

    case WXK_RIGHT:
        gnome->MovingRight();
        break;
    }
}

/**
 * The key up event function
 * @param event Key up event
 */
void StadiumView::OnKeyUp(wxKeyEvent& event)
{
    auto gnome = mStadium.GetGnome();
    switch (event.GetKeyCode())
    {
    case WXK_LEFT:
        gnome->ResetX();
        break;

    case WXK_RIGHT:
        gnome->ResetX();
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

    //
    // Prevent tunnelling
    //

    // Consume any remaining time

    auto size = GetClientSize();

    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));


    while(elapsed > MaxElapsed)
    {
        mStadium.Update(MaxElapsed);
        elapsed -= MaxElapsed;
    }
    if(elapsed>0)
    {
        mStadium.Update(elapsed);
    }

    graphics->PushState();

    mStadium.OnDraw(graphics,size.GetWidth(),size.GetHeight());

    auto GameMode = mStadium.GetGameMode();
    switch (*GameMode)
    {
    case 0:
    {
        int levelNum = mStadium.GetLevelNum();

        /// workaround for reloading levels upon loss/win
        mStadium.Load(levelNum);

        std::string strNum = to_string(levelNum);
        graphics->DrawText("Level" + strNum + " Begin",430,505);
        break;
    }
    case 1:
    {
//        graphics->DrawText("Level Complete", 550, 512);
        graphics->DrawText("Level Complete", 430, 505);
        break;
    }
    case 3:
    {
        graphics->DrawText("YOU LOSE!", 430, 505);
        break;
    }
    default:
    {
        break;
    }

    };



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
 * Add menus for game
 * @param mainFrame The main frame menu
 * @param menu The menu bar
 * @param levelMenu The level menu
 */
void StadiumView::AddMenus(wxFrame *mainFrame,wxMenuBar *menu, wxMenu* levelMenu)
{
    levelMenu->Append(IDM_ADDLEVEL0,L"Level0",L"load level0");
    levelMenu->Append(IDM_ADDLEVEL1,L"Level1",L"load level1");
    levelMenu->Append(IDM_ADDLEVEL2,L"Level2",L"load level2");
    levelMenu->Append(IDM_ADDLEVEL3,L"Level3",L"load level3");
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level0,this,IDM_ADDLEVEL0);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level1,this,IDM_ADDLEVEL1);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level2,this,IDM_ADDLEVEL2);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED,&StadiumView::Level3,this,IDM_ADDLEVEL3);

}

/**
 * Load level 0 menu
 * @param event The loading level 0 menu event
 */
void StadiumView::Level0(wxCommandEvent& event)
{
    mStadium.SetGameMode(0);
    mStadium.SetTime(-1);
    mStadium.Load(0);
}
/**
 * Load level 1 menu
 * @param event The loading level 1 menu event
 */
void StadiumView::Level1(wxCommandEvent& event)
{
    mStadium.SetGameMode(0);

    mStadium.SetTime(-1);
    mStadium.Load(1);
}
/**
 * Load level 2 menu
 * @param event The loading level 2 menu event
 */
void StadiumView::Level2(wxCommandEvent& event)
{
    mStadium.SetGameMode(0);
    mStadium.SetTime(-1);
    mStadium.Load(2);
}

/**
 * Load level 3 menu
 * @param event The loading level 3 menu event
 */
void StadiumView::Level3(wxCommandEvent& event)
{
    mStadium.SetGameMode(0);
    mStadium.SetTime(-1);
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
