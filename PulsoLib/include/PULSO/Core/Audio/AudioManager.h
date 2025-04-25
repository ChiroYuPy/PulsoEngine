//
// Created by ChiroYuki on 10/04/2025.
//

#ifndef WMG_AUDIOMANAGER_H
#define WMG_AUDIOMANAGER_H

#include <string>
#include <memory>
#include <unordered_map>
#include "miniaudio.h"

class AudioManager {
public:
    static AudioManager& get();

    ma_engine* getEngine();

    AudioManager(const AudioManager&) = delete;
    AudioManager& operator=(const AudioManager&) = delete;
    AudioManager(AudioManager&&) = delete;
    AudioManager& operator=(AudioManager&&) = delete;

private:
    AudioManager();
    ~AudioManager();

    ma_engine engine;
};

#endif //WMG_AUDIOMANAGER_H
