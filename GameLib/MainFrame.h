/**
 * @file MainFrame.h
 * @author SHOIMYA CHOWDHURY
 *
 *
 */

#ifndef SPARTYGNOME_MAINFRAME_H
#define SPARTYGNOME_MAINFRAME_H

#include <wx/wx.h>
/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:

public:
    void Initialize();
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

#endif //SPARTYGNOME_MAINFRAME_H
