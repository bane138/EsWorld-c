#include <iostream>
#include <string>
#include "CEsWorldScreen.h"
#include "CDialog.h"

using namespace std;

/**
 * @brief CDialog::CDialog
 */
CDialog::CDialog(void)
{

}

/**
 * @brief CDialog::~CDialog
 */
CDialog::~CDialog(void)
{

}

/**
 * @brief CDialog::createDialog
 * Create a dialog box with an image background
 * @param *screen CEsWorldScreen pointer to screen
 * @param background string the background image to use
 * @param x int x position
 * @param y int y position
 * @param clip SDL_Rect the clip coordinants of the background image
 */
void CDialog::createImageDialog(CEsWorldScreen *screen, std::string background,
                                int x, int y, SDL_Rect clip)
{
    screen->drawScreen(background, x, y, clip);
    m_nPositionX = x;
    m_nPositionY = y;
    m_nWidth = clip.w;
    m_nHeight = clip.h;
    m_bState = true;
}

/**
 * @brief CDialog::createBasicDialog
 * @param *screen CEsWorldScreen pointer to screen
 * @param x int x position
 * @param y int y position
 * @param m_nWidth int width
 * @param m_nHeight int height
 */
void CDialog::createBasicDialog(CEsWorldScreen *screen, int x, int y,
                                int m_nWidth, int m_nHeight)
{
    SDL_SetRenderDrawColor(screen->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect renderQuad = { x, y, m_nWidth, m_nHeight };
    SDL_SetRenderDrawColor(screen->getRenderer(), 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(screen->getRenderer(), &renderQuad);
    m_nPositionX = x;
    m_nPositionY = y;
    m_nWidth = m_nWidth;
    m_nHeight = m_nHeight;
    m_bState = true;
}

/**
 * @brief CDialog::showDialog
 */
void CDialog::showDialog()
{
    m_bState = true;
}

/**
 * @brief CDialog::closeDialog
 */
void CDialog::closeDialog()
{
    m_bState = false;
}
