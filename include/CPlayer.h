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
    int getXPosition(void) { return this->m_nXPosition; }
    /**
     * @brief setXPosition
     * @param x
     */
    void setXPosition(int x) { m_nXPosition = x; }
    /**
     * @brief getYPosition
     */
    int getYPosition(void) { return this->m_nYPosition; }
    /**
     * @brief setYPosition
     * @param y
     */
    void setYPosition(int y) { m_nYPosition = y; }
    /**
     * @brief getLives
     */
    int getLives(void) { return m_nLives; }
    /** this will be refactored */
    void drawPlayer(CEsWorldScreen *screen);
private:
    int m_nLives;
    int m_nXPosition;
    int m_nYPosition;
    SDL_Rect m_recBounds;
};

#endif // CPLAYER_H
