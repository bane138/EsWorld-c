#include <iostream>
#include "CSound.h"

CSound::CSound(void)
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
    }
}

CSound::~CSound(void)
{
    Mix_FreeMusic(m_mixMusic);
    Mix_FreeChunk(m_mixSound);
    Mix_Quit();
}

bool CSound::loadMusic(const char *file)
{
    if(!Mix_LoadMUS(file)) {
        std::cout << "Mix_LoadMUS error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}

bool CSound::loadSound(const char *file)
{
    if(!Mix_LoadWAV(file)) {
        std::cout << "Mix_LoadMUS error: " << Mix_GetError() << std::endl;
        return false;
    }
    return true;
}
