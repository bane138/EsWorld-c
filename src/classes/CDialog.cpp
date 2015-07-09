#include <iostream>
#include <string>
#include "CDialog.h"


using namespace std;

/**
 * @brief CDialog::CDialog
 */
CDialog::CDialog()
{

}

/**
 * @brief CDialog::~CDialog
 */
CDialog::~CDialog(void)
{

}

void CDialog::setScreen(CEsWorldScreen *screen)
{
    this->m_oScreen = screen;
}

void CDialog::createDialog(int x, int y, int width, int height)
{
    this->m_recClip->x = x;
    this->m_recClip->y = y;
    this->m_recClip->w = width;
    this->m_recClip->h = height;
    this->m_oScreen->drawScreen(x, y, this->m_recClip);

}

bool CDialog::showDialog()
{
    return true;
}

bool CDialog::closeDialog()
{
    return true;
}
