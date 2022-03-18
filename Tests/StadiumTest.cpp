/**
 * @file StadiumTest.cpp
 * @author Haoxiang Zhang
 */



#include <pch.h>
#include "gtest/gtest.h"
#include <Stadium.h>
#include <Picture.h>
#include <ItemPlatform.h>
#include <Gnome.h>
#include <Money.h>
#include <random>

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

using namespace std;

class StadiumTest : public ::testing::Test {
protected:
    /**
* Create a path to a place to put temporary files
*/
    wxString TempPath()
    {
        // Create a temporary filename we can use
        auto path = wxFileName::GetTempDir() + L"/project1";
        if(!wxFileName::DirExists(path))
        {
            wxFileName::Mkdir(path);
        }

        return path;
    }
    /**
    * Read a file into a wstring and return it.
    * @param filename Name of the file to read
    * @return File contents
    */
    wstring ReadFile(const wxString &filename)
    {
        ifstream t(filename.ToStdString());
        wstring str((istreambuf_iterator<char>(t)),
                istreambuf_iterator<char>());

        return str;
    }

    /**
* Test to ensure an aquarium .aqua file is empty
*/
    void TestEmpty(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;
        ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
//        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua/>")));
    }

    void TestItem(Stadium* stadium, wxString filename)
    {
        cout << "Temp file:" << filename << endl;
        auto picture = make_shared<Picture>(stadium);
        auto item1 = make_shared<Gnome>(stadium,picture);
    }

};

TEST_F(StadiumTest, Construct)
{
    Stadium stadium;
}
TEST_F(StadiumTest, HitTest)
{
    Stadium stadium;
    ASSERT_EQ(stadium.HitTest(100,200), nullptr) << L"Testing empty stadium";

    auto picture = make_shared<Picture>(&stadium);
    picture->SetImage(L"gnome.png");
    auto item = make_shared<Gnome>(&stadium,picture);
    item->SetLocation(100,200);
    }
