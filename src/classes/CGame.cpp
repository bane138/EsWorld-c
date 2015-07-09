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
 */
void CGame::startGame(void)
{
    m_bIsRunning = true;
    this->setupGame();
}

/**
 * @brief CGame::stopGame
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
    this->m_oScreen->setupScreen();
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
  * Draw the screen
  */
CEsWorldScreen* CGame::getScreen(void)
{
    return this->m_oScreen;
}


