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
    std::string background = "color_sheet.png";
    screen->drawScreen(background, m_nXPosition, m_nYPosition,
                       m_recBounds);
}
