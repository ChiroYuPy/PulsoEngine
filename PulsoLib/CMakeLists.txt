cmake_minimum_required(VERSION 3.30)
project(PulsoLib)

add_library(PulsoLib STATIC
        src/Graphics/Drawable.cpp
        src/Graphics/Containers/CompositeDrawable.cpp
        src/Graphics/Containers/Container.cpp
        src/Graphics/Containers/DebugContainer.cpp
        src/Math/Vector2.cpp
        src/Math/BoundingBox.cpp
        src/Core/Game.cpp
        src/Core/Scene/Scene.cpp
        src/Graphics/Shapes/Circle.cpp
        src/Graphics/Shapes/Shape.cpp
        src/Graphics/Shapes/Box.cpp
        src/Core/Scene/SceneStack.cpp
        src/Graphics/Containers/SearchContainer.cpp
        src/Transform/Transformable.cpp
        src/Transform/AnimationTransform.cpp
        src/Core/Clock.cpp
        src/Core/Time.cpp
        src/Core/Rendering/Renderer.cpp
        src/Core/GameContexte.cpp
        src/Graphics/Shapes/Text.cpp
        src/Core/Event/EventManager.cpp
        src/Core/Audio/AudioManager.cpp
        src/Core/Audio/Music.cpp
        src/Core/Audio/Sound.cpp
        src/Core/Audio/miniaudio_impl.cpp
        src/Math/Anchor.cpp
        src/Math/Rotation.cpp
        src/Graphics/Containers/GridContainer.cpp
        src/Graphics/Containers/ScrollContainer.cpp
        src/Graphics/Containers/BoxContainer.cpp
        src/Graphics/Interactives/Button.cpp
        src/Graphics/Label.cpp
        include/PULSO/Graphics/Label.h
)

target_include_directories(PulsoLib PUBLIC include)

target_link_libraries(PulsoLib PUBLIC sfml-system sfml-window sfml-graphics)