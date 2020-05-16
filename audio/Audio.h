//
// Created by samt on 03/05/2020.
//

#ifndef MUSICTOOLKIT_AUDIO_H
#define MUSICTOOLKIT_AUDIO_H

#include <cstdint>
#include <vector>
#include <optional>
#include <memory>
#include <mutex>
#include "IAudioUnit.h"
#include "IAudioWrapper.h"
#include <portaudio.h>
#include <iostream>

/// Collection of functions for configuring audio output
namespace MTK::Audio {
#define printErr(em) printf("PortAudio error: %s\n", Pa_GetErrorText(em)) //TODO: throw error

    class AudioSystem{
    public:
        ~AudioSystem(){
            audioInstance.reset();
            std::cout << "AudioSystem destructed"<< std::endl;
        }

        static AudioSystem* getAudioInstance(){
            std::call_once(aSInitFlag, [](){ instanceSystem.reset(new AudioSystem);});
            return instanceSystem.get();
        }

        template<typename T>
        int initialize(){
            std::call_once(initFlag, [this](){ audioInstance = std::unique_ptr<IAudioWrapper>(new T);});
            return 0;
        }

        int terminate();

        int setup(AudioSettings settings);

        int deviceCount();

        //TODO: Remove from the generic audio system class and so remove the portaudio include
        std::optional<const PaDeviceInfo *> getDeviceInfo(int i);

        int printDevices();

        int startStream();

        int stopStream();

        void setGenerator(std::shared_ptr<IAudioUnit> generator);

        std::shared_ptr<IAudioUnit> generator();

        AudioSettings getAudioSettings();

        uint64_t delta();

    private:
        AudioSystem() = default;
        AudioSystem(const AudioSystem&) = delete;
        AudioSystem& operator=(const AudioSystem&) = delete;

        std::unique_ptr<IAudioWrapper> audioInstance;
        std::once_flag initFlag;
        std::mutex audioInstanceMutex;
        std::once_flag delFlag;


        static std::unique_ptr<AudioSystem> instanceSystem;
        static std::once_flag aSInitFlag;
    };

}

#endif //MUSICTOOLKIT_AUDIO_H