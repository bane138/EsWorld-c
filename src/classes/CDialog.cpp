#include <iostream>
#include <string>
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
    this->m_oScreen = screen;
}

/**
 * @brief CDialog::createDialog
 * @param background
 * @param x
 * @param y
 * @param width
 * @param height
 */
void CDialog::createImageDialog(const std::string background, int x, int y, int width, int height)
{
    this->m_recClip->x = x;
    this->m_recClip->y = y;
    this->m_recClip->w = width;
    this->m_recClip->h = height;
    this->m_oScreen->drawScreen(background, x, y, this->m_recClip);

}

void CDialog::createBasicDialog(void)
{
    SDL_SetRenderDrawColor(this->m_oScreen->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(this->m_oScreen->getRenderer());
    SDL_Rect dialog = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
    SDL_SetRenderDrawColor(this->m_oScreen->getRenderer(), 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(this->m_oScreen->getRenderer(), &dialog);

    SDL_RenderPresent( this->m_oScreen->getRenderer() );
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
