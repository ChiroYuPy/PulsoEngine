cmake_minimum_required(VERSION 3.30)
project(WMG VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(PulsoLib)

add_executable(main WMGame/main.cpp
        WMGame/src/WMGame.cpp
        WMGame/src/Screens/MainMenuScreen.cpp
        WMGame/src/Screens/GameScreen.cpp
        WMGame/src/Screens/TestScreen.cpp
        WMGame/src/Graphics/Lane.cpp
        WMGame/src/Graphics/GridTest.cpp
        WMGame/src/Graphics/Buttons/BeatmapButton.cpp
        WMGame/src/Graphics/Containers/BeatmapCarrousel.cpp
        WMGame/src/Graphics/GameObjects/DrawableHitCircle.cpp
)

target_include_directories(main PUBLIC WMGame/include)

target_link_libraries(main PulsoLib)