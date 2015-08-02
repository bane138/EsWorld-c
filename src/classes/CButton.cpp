#include "CButton.h"

/**
 * @brief CButton::CButton
 */
CButton::CButton()
{
    m_ptPosition.x = 0;
    m_ptPosition.y = 0;

    m_nCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;

    // Moust out rec
    m_recSpriteClips[0].x = 0;
    m_recSpriteClips[0].y = 0;
    m_recSpriteClips[0].w = BUTTON_WIDTH;
    m_recSpriteClips[0].h = BUTTON_HEIGHT;
    // Mouse over rec
    m_recSpriteClips[1].x = 170;
    m_recSpriteClips[1].y = 0;
    m_recSpriteClips[1].w = BUTTON_WIDTH;
    m_recSpriteClips[1].h = BUTTON_HEIGHT;
    // mouse down rec
    m_recSpriteClips[2].x = 0;
    m_recSpriteClips[2].y = 140;
    m_recSpriteClips[2].w = BUTTON_WIDTH;
    m_recSpriteClips[2].h = BUTTON_HEIGHT;
    // mouse up rec
    m_recSpriteClips[3].x = 170;
    m_recSpriteClips[3].y = 140;
    m_recSpriteClips[3].w = BUTTON_WIDTH;
    m_recSpriteClips[3].h = BUTTON_HEIGHT;
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
 * @brief CButton::setTexture
 * @param screen
 * @param file
 */
void CButton::setTexture(CEsWorldScreen *screen, std::string file)
{
    m_tButtonSpriteTexture.loadFromFile(
                screen,
                screen->getResPath() + file.c_str());
}

/**
 * @brief CButton::handleEvent
 * @param e
 */
void CButton::handleEvent(SDL_Event* e)
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
    m_tButtonSpriteTexture.render(screen, m_ptPosition.x, m_ptPosition.y, &m_recSpriteClips[m_nCurrentSprite]);
}
