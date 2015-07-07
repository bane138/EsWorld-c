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
CDialog::~CDialog()
{

}

void CDialog::createDialog(int x, int y, int width, int height, const char *title)
{
    // SDL Window
    this->sdl_wWindow = SDL_CreateWindow(title,
                                            x,y,
                                            width, height,
                                            SDL_WINDOW_SHOWN);
    if(this->sdl_wWindow == nullptr) {
        logSDLError(std::cout, "SDL_CreateWindow");
        SDL_Quit();;
    }

    // SDL Renderer
    this->sdl_rRenderer = SDL_CreateRenderer(sdl_wWindow, -1,
                                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(this->sdl_rRenderer == nullptr) {
        logSDLError(std::cout, "SDL_Renderer");
        SDL_Quit();
    }
}

bool CDialog::showDialog(int x, int y)
{
    this->m_nPositionX = x;
    this->m_nPositionY = y;
    return true;
}

bool CDialog::closeDialog()
{
    return true;
}
