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

}

bool CDialog::showDialog()
{
    return true;
}

bool CDialog::closeDialog()
{
    return true;
}
