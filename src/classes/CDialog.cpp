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
 * @brief CDialog::setScreen
 * @param screen
 */
void CDialog::setScreen(CEsWorldScreen *screen)
{
    //m_sdlScreen = screen;
}

/**
 * @brief CDialog::createDialog
 * @param background
 * @param x
 * @param y
 * @param width
 * @param height
 */
void CDialog::createImageDialog(CEsWorldScreen *screen, std::string background,
                                int x, int y, int width, int height)
{
    m_recClip->x = x;
    m_recClip->y = y;
    m_recClip->w = width;
    m_recClip->h = height;
    screen->drawScreen(screen->getResPath() + background, x, y, *m_recClip);

}

void CDialog::createBasicDialog(CEsWorldScreen *screen, int x, int y,
                                int m_nWidth, int m_nHeight)
{
    SDL_SetRenderDrawColor(screen->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect renderQuad = { x, y, m_nWidth, m_nHeight };
    SDL_RenderClear(screen->getRenderer());
    SDL_Rect dialog = { 10, 10, 100, 200 };
    if(&dialog != NULL) {
        renderQuad.w = dialog.w;
        renderQuad.h = dialog.h;
    }
    SDL_SetRenderDrawColor(screen->getRenderer(), 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderCopy(screen->getRenderer(), NULL, &dialog, &renderQuad);
    //SDL_RenderFillRect(screen->getRenderer(), &dialog);

    SDL_RenderPresent(screen->getRenderer());
}

/**
 * @brief CDialog::showDialog
 */
void CDialog::showDialog()
{
    this->m_nState = true;
}

/**
 * @brief CDialog::closeDialog
 */
void CDialog::closeDialog()
{
    this->m_nState = false;
}
