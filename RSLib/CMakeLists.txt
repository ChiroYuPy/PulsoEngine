cmake_minimum_required(VERSION 3.30)
project(RSLib)

add_library(RSLib STATIC
        src/Graphics/Drawable.cpp
        src/Graphics/Containers/CompositeDrawable.cpp
        src/Graphics/Containers/Container.cpp
        src/Graphics/Containers/DebugContainer.cpp
        src/Core/Rendering/SFMLRenderer.cpp
        src/Math/Vector2.cpp
        src/Math/BoundingBox.cpp
        src/Core/GameBase.cpp
        src/Core/Game.cpp
        src/Core/Scene/Scene.cpp
        src/Graphics/Shapes/Circle.cpp
        src/Graphics/Shapes/Shape.cpp
        src/Graphics/Shapes/Box.cpp
        src/Core/Scene/SceneStack.cpp
        src/Graphics/Containers/IFilterable.cpp
        src/Graphics/Containers/SearchContainer.cpp
        src/Transform/Transformable.cpp
        src/Transform/AnimationTransform.cpp
        src/Core/Clock.cpp
        src/Core/Time.cpp
        src/Core/Color.cpp
        src/Core/Rendering/MockRenderer.cpp
        src/Core/Rendering/IRenderer.cpp
        src/Core/GameContexte.cpp
        src/Graphics/Shapes/Text.cpp
        src/Core/Audio/AudioManager.cpp
        include/RS/Core/Audio/AudioManager.h
        src/Core/Audio/Music.cpp
        include/RS/Core/Audio/Music.h
        src/Core/Audio/Sound.cpp
        include/RS/Core/Audio/Sound.h
        src/Core/Audio/miniaudio_impl.cpp
        src/Math/Anchor.cpp
        include/RS/Math/Anchor.h
        src/Graphics/Containers/FillFlowContainer.cpp
        include/RS/Graphics/Containers/FillFlowContainer.h
        src/Graphics/Containers/GridContainer.cpp
        include/RS/Graphics/Containers/GridContainer.h
        src/Graphics/Interactives/DrawableInteractable.cpp
        include/RS/Graphics/Interactives/DrawableInteractable.h
        src/Graphics/Interactives/Button.cpp
        include/RS/Graphics/Interactives/Button.h
)

target_include_directories(RSLib PUBLIC include)

target_link_libraries(RSLib PUBLIC sfml-system sfml-window sfml-graphics)