#ifndef CDIALOG_H
#define CDIALOG_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "CEsWorldScreen.h"

using namespace std;

/**
 * @brief The CDialog class
 * Create and maintain game dialogs.Game dialogs examples are chat
 * windows, game lists and menus, score displays etc.
 */
class CDialog
{
public:
    /* Constructor */
    CDialog();
    /* Destructor */
    ~CDialog(void);
    /**
     * @brief setScreen
     * @param screen
     */
    void setScreen(CEsWorldScreen *screen);
    /**
     * @brief createImageDialog
     * @param background
     * @param x
     * @param y
     * @param width
     * @param height
     */
    void createImageDialog(CEsWorldScreen *screen, std::string background,
                           int x, int y, int width, int height);
    /**
     * @brief createBasicDialog
     */
    void createBasicDialog(CEsWorldScreen *screen, int x, int y,
                           int m_nWidth, int m_nHeight);
    /* showDialog display at x y */
    void showDialog();
    /**
     * @brief closeDialog
     * @return
     */
    void closeDialog(void);
    /**
     * @brief getWidth
     * @return
     */
    int getWidth(void) const { return m_nWidth; }
    /**
     * @brief getHeight
     * @return
     */
    int getHeight(void) const { return m_nHeight; }
private:
    void setWidth(int width) { m_nWidth = width; }
    void setHeight(int height) { m_nHeight = height; }
    //CEsWorldScreen m_sdlScreen;
    SDL_Rect *m_recDestination;
    SDL_Rect *m_recClip;
    int m_nWidth;
    int m_nHeight;
    int m_nPositionX;
    int m_nPositionY;
    int m_nState;
};

#endif // CDIALOG_H
