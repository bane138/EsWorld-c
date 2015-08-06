#ifndef CSOUND_H
#define CSOUND_H

#include <SDL.h>
#include <SDL_mixer.h>

#include "res_path.h"

class CSound
{
public:
    CSound(void);
    ~CSound(void);

    void loadMusic(void);
    void loadSound(void);
private:
    std::string getResPath(void);

    Mix_Music* m_mixMusic;
    Mix_Chunck* m_mixSound;
};

#endif // CSOUND_H

