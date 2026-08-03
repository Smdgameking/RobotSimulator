#include "TTS.h"

#include <cstdlib>

void TTS::Speak(const std::string& text)
{
#ifdef __ANDROID__

    std::string command =
        "termux-tts-speak \"" + text + "\"";

    system(command.c_str());

#else

    std::string command =
        "espeak \"" + text + "\"";

    system(command.c_str());

#endif
}
