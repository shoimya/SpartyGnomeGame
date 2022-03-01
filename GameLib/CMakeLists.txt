project(GameLib)

set(SOURCE_FILES)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

set(SOURCE_FILES MainFrame.cpp MainFrame.h pch.h StadiumView.cpp StadiumView.h Item.cpp Item.h Stadium.cpp Stadium.h ids.h Vector.cpp Vector.h Picture.cpp Picture.h Platform.cpp Platform.h Door.cpp Door.h ScoreBoard.cpp ScoreBoard.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
