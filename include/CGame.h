#ifndef CGAME_H
#define CGAME_H
#include "CEsWorldScreen.h"
#include <string>
#include <map>
#include <vector>

class CGame
{
public:
    CGame(void);
    ~CGame(void);
    /**
     * Setup game
     * Initialize game specific data
     */
    void startGame(void);
    void stopGame(void);
    CEsWorldScreen getScreen(void);

    bool isGameRunning(void) { return m_bIsRunning; }
    int getLevel(void) { return m_nLevel; }
private:
    /* Methods */
    void setupGame(void);
    /* Properties */
    bool m_bIsRunning;
    int m_nLevel;
    CEsWorldScreen m_sdlScreen;
    std::map<std::string, int> m_mGameData;
    //CPlayer m_oPlayer
};

#endif // CGAME_H
