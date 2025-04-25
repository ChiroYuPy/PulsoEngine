//
// Created by ChiroYuki on 10/04/2025.
//

#include "PULSO/Core/Audio/Music.h"

#include <stdexcept>
#include <iostream>

Music::Music(const std::string& filepath, bool loop) {
    auto& am = AudioManager::get();
    ma_result result = ma_sound_init_from_file(am.getEngine(), filepath.c_str(), 0, nullptr, nullptr, &sound);
    if (result != MA_SUCCESS) {
        throw std::runtime_error("Failed to load music: " + filepath);
    }

    length = calculateLength();
    ma_sound_set_looping(&sound, loop);
}

Music::~Music() {
    std::cout << "[Music] Destroying music..." << std::endl;
    ma_sound_uninit(&sound);
    std::cout << "[Music] Music destroyed." << std::endl;
}

void Music::start() {
    std::cout << "[Music] Playing music..." << std::endl;
    ma_result result = ma_sound_start(&sound);
    if (result != MA_SUCCESS)
        std::cerr << "[Music] Failed to start sound! Error code: " << result << std::endl;
    else
        std::cout << "[Music] Music is playing." << std::endl;
}

void Music::pause() {
    std::cout << "[Music] Pausing music." << std::endl;
    ma_sound_stop(&sound);
}

void Music::resume() {
    std::cout << "[Music] Resuming music." << std::endl;
    ma_sound_start(&sound);
}

void Music::stop() {
    std::cout << "[Music] Stopping music." << std::endl;
    ma_sound_stop(&sound);
}

void Music::restart() {
    std::cout << "[Music] Restarting music." << std::endl;
    seek(0.0);
    start();
}

void Music::setLooping(bool loop) {
    std::cout << "[Music] Setting looping to " << (loop ? "true" : "false") << std::endl;
    ma_sound_set_looping(&sound, loop);
}

bool Music::isLooping() const {
    bool looping = ma_sound_is_looping(&sound);
    std::cout << "[Music] isLooping() -> " << (looping ? "true" : "false") << std::endl;
    return looping;
}

bool Music::isPlaying() const {
    bool playing = ma_sound_is_playing(&sound);
    std::cout << "[Music] isPlaying() -> " << (playing ? "true" : "false") << std::endl;
    return playing;
}

bool Music::isFinished() const {
    bool finished = ma_sound_at_end(&sound);
    std::cout << "[Music] isFinished() -> " << (finished ? "true" : "false") << std::endl;
    return finished;
}

double Music::getCurrentTimeSeconds() {
    ma_uint64 frame = 0;
    ma_sound_get_cursor_in_pcm_frames(&sound, &frame);

    ma_uint32 sampleRate = ma_engine_get_sample_rate(AudioManager::get().getEngine());
    double seconds = static_cast<double>(frame) / sampleRate;
    std::cout << "[Music] Current playback time: " << seconds << "s" << std::endl;
    return seconds;
}

double Music::getLength() const {
    return length;
}

double Music::calculateLength() {
    ma_uint64 totalFrames = 0;
    ma_sound_get_length_in_pcm_frames(&sound, &totalFrames);

    ma_uint32 sampleRate = ma_engine_get_sample_rate(AudioManager::get().getEngine());
    double l = static_cast<double>(totalFrames) / sampleRate;
    return l;
}

void Music::seek(double seconds) {
    ma_uint32 sampleRate = ma_engine_get_sample_rate(AudioManager::get().getEngine());
    ma_uint64 frame = static_cast<ma_uint64>(seconds * sampleRate);

    ma_result result = ma_sound_seek_to_pcm_frame(&sound, frame);
    if (result != MA_SUCCESS) {
        std::cerr << "[Music] Error seeking to " << seconds << "s. Error code: " << result << std::endl;
    } else {
        std::cout << "[Music] Seeking to " << seconds << "s (" << frame << " frames)" << std::endl;
    }
}

void Music::setVolume(float volume) {
    std::cout << "[Music] Setting volume to " << volume << std::endl;
    ma_sound_set_volume(&sound, volume);
}

float Music::getVolume() const {
    float volume = ma_sound_get_volume(&sound);
    std::cout << "[Music] Current volume: " << volume << std::endl;
    return volume;
}

void Music::setPitch(float pitch) {
    std::cout << "[Music] Setting pitch to " << pitch << std::endl;
    ma_sound_set_pitch(&sound, pitch);
}

void Music::setPan(float pan) {
    std::cout << "[Music] Setting pan to " << pan << " (-1=left, 0=center, 1=right)" << std::endl;
    ma_sound_set_pan(&sound, pan);
}