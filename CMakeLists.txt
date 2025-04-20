cmake_minimum_required(VERSION 3.30)
project(WMG VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(RSLib)

add_executable(main WMGame/main.cpp
        WMGame/src/MyGame.cpp
        WMGame/src/Screens/MainMenuScreen.cpp
        WMGame/src/Screens/GameScreen.cpp
        WMGame/include/Screens/GameScreen.h
        WMGame/src/Graphics/Lane.cpp
        WMGame/include/Graphics/Lane.h
        WMGame/src/Graphics/GridTest.cpp
        WMGame/include/Graphics/GridTest.h
        WMGame/src/Graphics/BeatmapButton.cpp
        WMGame/include/Graphics/BeatmapButton.h
)

target_include_directories(main PUBLIC WMGame/include)

target_link_libraries(main RSLib)