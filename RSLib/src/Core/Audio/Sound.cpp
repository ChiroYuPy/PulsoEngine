//
// Created by ChiroYuki on 10/04/2025.
//

#include "RS/Core/Audio/Sound.h"
#include <iostream>
#include <stdexcept>
#include <utility>

static int INSTANCES = 0;
constexpr int MAX_INSTANCES = 100;

SoundInstance::SoundInstance(ma_engine* engine, const std::string& filepath) {
    INSTANCES++;
    if (ma_sound_init_from_file(engine, filepath.c_str(), 0, nullptr, nullptr, &sound) != MA_SUCCESS) {
        throw std::runtime_error("Failed to load sound instance: " + filepath);
    }
}

SoundInstance::~SoundInstance() {
    INSTANCES--;
    ma_sound_uninit(&sound);
}

void SoundInstance::play() {
    ma_uint64 totalFrames = 0;
    ma_sound_get_length_in_pcm_frames(&sound, &totalFrames);

    ma_uint32 sampleRate = ma_engine_get_sample_rate(AudioManager::get().getEngine());
    double seconds = static_cast<double>(totalFrames) / sampleRate;
    std::cout << INSTANCES << " " << seconds << std::endl;
    ma_sound_start(&sound);
}

void SoundInstance::stop() {
    ma_sound_stop(&sound);
}

bool SoundInstance::isPlaying() const {
    return ma_sound_is_playing(&sound);
}

void SoundInstance::setVolume(float volume) {
    ma_sound_set_volume(&sound, volume);
}

float SoundInstance::getVolume() const {
    return ma_sound_get_volume(&sound);
}

Sound::Sound(std::string  filepath) : filepath(std::move(filepath)) {}

Sound::~Sound() {
    instances.clear();
}

void Sound::play() {
    for (auto& instance : instances) {
        if (!instance->isPlaying()) {
            instance->setVolume(defaultVolume);
            instance->play();
            return;
        }
    }

    if (INSTANCES >= MAX_INSTANCES) {
        throw std::runtime_error("Too many instances have been created, consider shortening the audio file");
    }

    auto* engine = AudioManager::get().getEngine();
    try {
        auto newInstance = std::make_unique<SoundInstance>(engine, filepath);
        newInstance->setVolume(defaultVolume);
        newInstance->play();
        instances.push_back(std::move(newInstance));
    } catch (const std::exception& e) {
        std::cerr << "[Sound] Error: " << e.what() << std::endl;
    }
}

void Sound::setVolume(float volume) {
    defaultVolume = volume;
}