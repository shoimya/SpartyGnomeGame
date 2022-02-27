project(GameLib)

set(SOURCE_FILES)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

set(SOURCE_FILES MainFrame.cpp MainFrame.h pch.h StadiumView.cpp StadiumView.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})