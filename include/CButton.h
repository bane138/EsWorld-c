#ifndef CBUTTON_H
#define CBUTTON_H

#include <SDL.h>
#include "CTexture.h"

const int BUTTON_WIDTH = 150;
const int BUTTON_HEIGHT = 100;
const int TOTAL_BUTTONS = 4;

enum CButtonSprite
{
    BUTTON_SPRITE_MOUSE_OVER_MOTION = 0,
    BUTTON_SPRITE_MOUSE_OUT = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

class CButton
{
public:
    /**
     * @brief CButton
     */
    CButton();
    ~CButton(void);
    /**
     * @brief setPosition
     * @param x
     * @param y
     */
    void setPosition(int x, int y);
    /**
     * @brief setTexture
     * @param screen
     * @param file
     */
    void setTexture(CEsWorldScreen* screen,  std::string file);
    /**
     * @brief handleEvent
     * @param e
     */
    void handleEvent(SDL_Event* e);
    /**
     * @brief render
     */
    void render(CEsWorldScreen* screen);
private:
    /**
     * @brief SDL_Point m_ptPosition
     */
    SDL_Point m_ptPosition;
    /**
     * @brief CButtonSprite m_btnCurrentSprite
     */
    CButtonSprite m_nCurrentSprite;
    CTexture m_tButtonSpriteTexture;
    SDL_Rect m_recSpriteClips[BUTTON_SPRITE_TOTAL];
};

#endif // CBUTTON_H
