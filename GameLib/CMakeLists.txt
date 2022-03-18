project(GameLib)

set(SOURCE_FILES MainFrame.cpp MainFrame.h pch.h StadiumView.cpp StadiumView.h Item.cpp Item.h Stadium.cpp Stadium.h ids.h Vector.cpp Vector.h Picture.cpp Picture.h Platform.cpp Platform.h Door.cpp Door.h Level.cpp Level.h Background.cpp Background.h Gnome.cpp Gnome.h Visitor.cpp Visitor.h ItemPlatform.cpp ItemPlatform.h ItemPlatform.cpp ItemPlatform.h Money.cpp Money.h Stanley.cpp Stanley.h Wall.cpp Wall.h Grass.cpp Grass.h Snow.cpp Snow.h VisitorDoor.cpp VisitorDoor.h TreasureBox.cpp TreasureBox.h Villain.cpp Villain.h VisitorVillain.cpp VisitorVillain.h VisitorMoney.cpp VisitorMoney.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
