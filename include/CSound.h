#ifndef CSOUND_H
#define CSOUND_H

#include <string>
#include <SDL.h>
#include <SDL_mixer.h>

//#include "res_path.h"

class CSound
{
public:
    CSound(void);
    ~CSound(void);

    bool loadMusic(const char* file);
    bool loadSound(const char* file);
private:
    std::string getResPath(void);

    Mix_Music* m_mixMusic;
    Mix_Chunk* m_mixSound;
};

#endif // CSOUND_H

