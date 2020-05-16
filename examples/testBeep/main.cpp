
#include <iostream>
#include <Audio.h>
#include <cmath>
#include <AudioUnits/Beep.h>
#include <thread>
#include <AudioUnits/Oscillators/SawWave.h>
#include <AudioUnits/Oscillators/SinWave.h>
#include <PortAudioWrapper.h>

int main(int argc, char *argv[]){
    MTK::Audio::AudioSystem::getAudioInstance()->initialize<MTK::Audio::PortAudioWrapper>();
    MTK::Audio::AudioSystem::getAudioInstance()->setup({1, 44100, 0});
    auto beep = std::make_shared<MTK::Audio::Beep>();
    beep->addVoices<MTK::Audio::SinWave>(1);
    MTK::Audio::AudioSystem::getAudioInstance()->setGenerator(beep);
    MTK::Audio::AudioSystem::getAudioInstance()->startStream();

    beep->NoteOn(0, {{0, 500.f}});
    auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(4000);
    std::this_thread::sleep_until(x);
    beep->NoteOff(0, {});
    x = std::chrono::steady_clock::now() + std::chrono::milliseconds(500);
    std::this_thread::sleep_until(x);


    if(auto err = MTK::Audio::AudioSystem::getAudioInstance()->stopStream() != 0) {
        std::cout << "stream may not have stopped correctly";
    }
    std::cout << "Stream stopped" << std::endl;

    MTK::Audio::AudioSystem::getAudioInstance()->terminate();

    std::cout << "Pa terminated" << std::endl;
    return 0;
}