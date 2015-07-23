#include <string>
#include "CPlayer.h"

/**
 * @brief CPlayer::CPlayer
 */
CPlayer::CPlayer(void)
{
    m_recBounds.x = 0;
    m_recBounds.y = 0;
    m_recBounds.w = 100;
    m_recBounds.h = 100;
}

/**
 * @brief CPlayer::~CPlayer
 */
CPlayer::~CPlayer(void)
{

}

void CPlayer::drawPlayer(CEsWorldScreen *screen)
{
    m_tTexture.loadFromFile(screen, screen->getResPath() + "dude.png",
                            0, 0xFF, 0xFF);
    m_tTexture.render(screen, m_nXPosition, m_nYPosition, &m_recBounds);
}
