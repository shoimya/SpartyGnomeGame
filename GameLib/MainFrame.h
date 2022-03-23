/**
 * @file MainFrame.h
 * @author SHOIMYA CHOWDHURY
 *
 *
 */

#ifndef SPARTYGNOME_MAINFRAME_H
#define SPARTYGNOME_MAINFRAME_H

#include <wx/wx.h>

class StadiumView;
/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:
    ///  StadiumView in MainFrame
    StadiumView*  mStadiumView;

public:
    ///  Initialize MainFrame
    void Initialize();

    /**  OnExit -> exit program
    * @param event wxCommandEvent of clicking exit button */
    void OnExit(wxCommandEvent& event);

    /**  OnAbout -> about program
    * @param event wxCommandEvent of clicking about button */
    void OnAbout(wxCommandEvent& event);
};

#endif //SPARTYGNOME_MAINFRAME_H
