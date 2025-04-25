//
// Created by ChiroYuki on 10/04/2025.
//

#ifndef WMG_MUSIC_H
#define WMG_MUSIC_H

#include <string>
#include "miniaudio.h"
#include "AudioManager.h"

class Music {
public:
    Music(const std::string& filepath, bool loop = true);
    ~Music();

    void setLooping(bool loop);
    [[nodiscard]] bool isPlaying() const;
    double getCurrentTimeSeconds();
    void seek(double seconds);

    void setVolume(float volume);
    [[nodiscard]] float getVolume() const;

    void setPitch(float pitch);
    void setPan(float pan);

    double getLength() const;

    bool isFinished() const;
    bool isLooping() const;

    void start();
    void stop();
    void restart();
    void pause();
    void resume();

private:
    double length = 0;

    double calculateLength();

    ma_sound sound{};
    ma_engine* engine{};
};

#endif //WMG_MUSIC_H
