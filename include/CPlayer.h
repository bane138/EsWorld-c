#ifndef CPLAYER_H
#define CPLAYER_H

#include <SDL.h>

#include "CEsWorldScreen.h"

class CPlayer
{
public:
    /**
     * @brief CPlayer
     */
    CPlayer(void);
    /**
     * @brief ~CPlayer
     */
    ~CPlayer(void);
    /**
     * @brief getWidth
     */
    int getWidth(void) { return m_recBounds.w; }
    /**
     * @brief getHeight
     */
    int getHeight(void) { return m_recBounds.h; }
    /**
     * @brief getXPosition
     */
    int getXPosition(void) { return m_recBounds.x; }
    /**
     * @brief setXPosition
     * @param x
     */
    void setXPosition(int x) { m_recBounds.x = x; }
    /**
     * @brief getYPosition
     */
    int getYPosition(void) { return m_recBounds.y; }
    /**
     * @brief setYPosition
     * @param y
     */
    void setYPosition(int y) { m_recBounds.y = y; }
    /**
     * @brief getLives
     */
    int getLives(void) { return m_nLives; }
    /** this will be refactored */
    void drawPlayer(CEsWorldScreen *screen);
private:
    int m_nLives;
    SDL_Rect m_recBounds;
};

#endif // CPLAYER_H
