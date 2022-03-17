/**
 * @file MainFrame.cpp
 * @author SHOIMYA CHOWDHURY
 */
#include "pch.h"
#include "MainFrame.h"
#include "StadiumView.h"
#include "ids.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Sparty Gnome Game",
            wxDefaultPosition,  wxSize( 1000,800 ));

    // Creates a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Creates the view class object as a child of MainFrame
    mStadiumView = new StadiumView();
    mStadiumView->Initialize(this);

    // Add it to the sizer
    sizer->Add(mStadiumView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    CreateStatusBar();
    // Layout (place) the child windows.
    Layout();
    
    auto menuBar = new wxMenuBar( );

    auto fileMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto levelMenu = new wxMenu();


    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");


    //    the bindings
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(levelMenu, L"&Levels");
    mStadiumView->AddMenus(this,menuBar,levelMenu);
    menuBar->Append(helpMenu, L"&Help");

    SetMenuBar( menuBar );

}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    mStadiumView->Stop();
    Destroy();
}

/**
 * About menu option handlers
 * @param event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox(L"Sparty Gnome Game By Wario!",
            L"About Game",
            wxOK,
            this);
}