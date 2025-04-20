//
// Created by ChiroYuki on 10/04/2025.
//

#include "RS/Core/Audio/AudioManager.h"

#include <stdexcept>
#include <iostream>

AudioManager::AudioManager() {
    std::cout << "[AudioManager] Initializing audio engine..." << std::endl;
    if (ma_engine_init(nullptr, &engine) != MA_SUCCESS) {
        throw std::runtime_error("Failed to initialize audio engine.");
    }
    std::cout << "[AudioManager] Audio engine initialized successfully." << std::endl;
}

AudioManager::~AudioManager() {
    ma_engine_uninit(&engine);
}

AudioManager& AudioManager::get() {
    static AudioManager instance;
    return instance;
}

ma_engine* AudioManager::getEngine() {
    return &engine;
}