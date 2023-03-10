cmake_minimum_required(VERSION 3.5)

project(maze VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    ../src/main.cc
    ../src/view/widget.cc
    ../src/view/widget.h
    ../src/view/widget.ui
    ../src/view/scene.cc
    ../src/view/cave_scene.cc
    ../src/view/maze_scene.cc
    ../src/controllers/cave_controller.h
    ../src/controllers/maze_controller.h
    ../src/cave/cave.h
    ../src/cave/cave.cc
    ../src/cave/part5.cc
    ../src/maze_v2/maze.cc
    ../src/maze_v2/maze.h
    ../src/helpers/helpers.h
)

set(MACOSX_BUNDLE_ICON_FILE MyIcon.icns)
set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/MyIcon.icns")
set_source_files_properties(${app_icon_macos} PROPERTIES
           MACOSX_PACKAGE_LOCATION "Resources")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(maze
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${app_icon_macos}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET maze APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(maze SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(maze
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(maze PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(maze PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(maze)
endif()
