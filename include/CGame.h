#ifndef CGAME_H
#define CGAME_H
#include "CEsWorldScreen.h"
#include <map>
#include <vector>

using namespace std;

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
    bool isGameRunning(void) { return m_bIsRunning; }
private:
    /* Methods */
    void setupGame(void);
    /* Properties */
    bool m_bIsRunning;
    int m_nLevel;
    int m_nScore;
    CEsWorldScreen m_oScreen;
    std::map<std::string, int> m_mGameData;
    //CPlayer m_oPlayer
};

#endif // CGAME_H
