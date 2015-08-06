#include <string>

#include "CSound.h"

CSound::CSound(void)
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::count << "Mix_OpenAudio error: " << Mix_GetError() << std::endl;
        return false;
    }
}

CSound::~CSound(void)
{
    Mix_FreeChunk(m_mixSound);
    Mix_FreeMusic(m_mixMusic);
    Mix_Quit();
}

void CSound::loadMusic(std::string file)
{
    m_mixMusic = Mix_LoadMUS(getResPath() + file);
    if(m_mixMusic == NULL) {
        std::cout << "Mix_LoadMUS error: " << Mix_GetError() << std:endl;
    }
}

void CSound::loadSound(std::string file)
{
    m_mixSound = Mix_LoadWAV(getResPath() + file);
    if(m_mixSound == NULL) {
        std::cout << "Mix_LoadWAV error: " << Mix_GetError() << std:endl;
    }
}

std::string CSound::getResPath(void)
{
    return getResourcePath(RESOURCE_PATH);
}
