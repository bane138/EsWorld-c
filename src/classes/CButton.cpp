#include "CButton.h"

/**
 * @brief CButton::CButton
 */
CButton::CButton(void)
{
    m_ptPosition.x = 0;
    m_ptPosition.y = 0;

    m_nCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

/**
 * @brief CButton::~CButton
 */
CButton::~CButton()
{

}

/**
 * @brief CButton::setPosition
 * @param x
 * @param y
 */
void CButton::setPosition(int x, int y)
{
    m_ptPosition.x = x;
    m_ptPosition.y = y;
}

/**
 * @brief CButton::handleEvent
 * @param e
 */
void CButton::handleEvent(SDL_Event *e)
{
    // If mouse event happened
    if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN ||
            e->type == SDL_MOUSEBUTTONUP) {
        // Get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        // Check if the mouse is in a button
        bool inside = true;

        // If is left on mouse button
        if(x < m_ptPosition.x) {
            inside = false;
        } else if(x > m_ptPosition.x + BUTTON_WIDTH) {
            inside = false;
        } else if(y < m_ptPosition.y) {
            inside = false;
        } else if(y > m_ptPosition.y + BUTTON_HEIGHT) {
            inside =  false;
        }

        if(!inside) {
            m_nCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
        } else {
            // Set mouse over sprite
            switch(e->type) {
                case SDL_MOUSEMOTION:
                    m_nCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    m_nCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                    break;
                case SDL_MOUSEBUTTONUP:
                    m_nCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
                    break;
            }
        }
    }
}

void CButton::render(CEsWorldScreen* screen)
{
    // Show current button sprite
    m_tCurrentButtonSpriteTexture.render(screen, m_ptPosition.x, m_ptPosition.y, &m_recSpriteClips[m_nCurrentSprite]);
}
