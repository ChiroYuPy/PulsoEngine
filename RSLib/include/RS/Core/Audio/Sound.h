//
// Created by ChiroYuki on 10/04/2025.
//

#ifndef WMG_SOUND_H
#define WMG_SOUND_H

#include <string>
#include <vector>

#include "Sound.h"
#include "AudioManager.h"

class SoundInstance {
public:
    SoundInstance(ma_engine* engine, const std::string& filepath);
    ~SoundInstance();

    void play();
    void stop();
    bool isPlaying() const;
    void setVolume(float volume);
    float getVolume() const;

private:
    ma_sound sound{};
};

class Sound {
public:
    explicit Sound(std::string  filepath);
    ~Sound();

    void play();
    void setStartPos(float position);
    void setVolume(float volume);

private:
    std::string filepath;
    std::vector<std::unique_ptr<SoundInstance>> instances;
    float defaultVolume = 1.0f;
};

#endif //WMG_SOUND_H
