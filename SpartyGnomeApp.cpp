/**
 * @file  SpartyGnomeApp.cpp
 * @author Shoimya Chowdhury
 */
#include "pch.h"
#include "MainFrame.h"
#include "SpartyGnomeApp.h"

/**
 * Initialize the application.
 * @return
 */
bool SpartyGnomeApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);


    return true;
}

