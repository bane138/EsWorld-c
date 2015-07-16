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
 * @param width int width
 * @param height int height
 */
void CDialog::createBasicDialog(CEsWorldScreen *screen, int x, int y,
                                int width, int height, SDL_Color color)
{
    SDL_SetRenderDrawColor(screen->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect renderQuad = { x, y, m_nWidth, m_nHeight };
    SDL_SetRenderDrawColor(screen->getRenderer(), color.r, color.b,
                           color.g, color.a);
    SDL_RenderFillRect(screen->getRenderer(), &renderQuad);
    m_nPositionX = x;
    m_nPositionY = y;
    m_nWidth = width;
    m_nHeight = height;
    m_bState = true;
}
/**
 * @brief createTextDialog
 * Create a basic text dialog
 * @param *screen CEsWorldScreen pointer to screen
 * @param x int x position
 * @param y int y position
 * @param width int width
 * @param height int height
 * @param text string text to display
 */
void CDialog::createTextDialog(CEsWorldScreen *screen, int x, int y,
                               int width, int height,
                               const std::string *text,
                               SDL_Color fillColor, SDL_Color textColor)
{
    SDL_SetRenderDrawColor(screen->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_Rect renderQuad = { x, y, width, height };
    SDL_SetRenderDrawColor(screen->getRenderer(),  fillColor.r, fillColor.b,
                           fillColor.g, fillColor.a);
    SDL_RenderFillRect(screen->getRenderer(), &renderQuad);
    screen->drawText(*text,
                     x + 10, y + 10,
                     textColor);
    m_nPositionX = x;
    m_nPositionY = y;
    m_nWidth = width;
    m_nHeight = height;
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
