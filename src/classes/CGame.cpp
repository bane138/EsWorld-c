#include "CGame.h"
#include "CEsWorldScreen.h"
#include <map>
#include <vector>

using namespace std;

/**
 * @brief CGame::CGame
 */
CGame::CGame(void)
{
    m_bIsRunning = false;
}

/**
 * @brief CGame::~CGame
 */
CGame::~CGame(void)
{
    m_bIsRunning = false;
}

/**
 * @brief CGame::startGame
 * Set m_bIsRunning to true
 * Setup the game
 */
void CGame::startGame(void)
{
    m_bIsRunning = true;
    setupGame();
}

/**
 * @brief CGame::stopGame
 * Set m_bIsRunning to false
 */
void CGame::stopGame(void)
{
    m_bIsRunning = false;
}

/**
 * @brief CGame::setupGame
 * Setup initial game state
 */
void CGame::setupGame(void)
{
    /**
     * Setup screen for the game
     */
    CEsWorldScreen m_sdlScreen;
    m_sdlScreen.setupScreen();
    /**
    //CPlayer *m_oPlayer;
    */
    /**
     * Need some way of loading save data here
     * stub for now
     */
    //std::map<string, int> *m_mGameData;
    this->m_mGameData["level"] = 1;
    if(!m_mGameData.empty()) {
    } else {
        m_nLevel = 1;
    }
}

/**
  * Return the screen instance for drawing
  */
CEsWorldScreen CGame::getScreen(void)
{
    m_sdlScreen.setupScreen();
    return m_sdlScreen;
}


