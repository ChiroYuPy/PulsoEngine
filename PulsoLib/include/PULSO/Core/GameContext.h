//
// Created by ChiroYuki on 10/04/2025.
//

#ifndef WMG_GAMECONTEXT_H
#define WMG_GAMECONTEXT_H

class SceneStack;
class Renderer;
class EventManager;

class GameContext {
public:
    SceneStack* screenStack = nullptr;
    Renderer* renderer = nullptr;
    EventManager* eventDispacher = nullptr;

    // AudioManager Audio;
    // InputManager input;
    // AssetManager assets;
    // ConfigManager config;
};


#endif //WMG_GAMECONTEXT_H
