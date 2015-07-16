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
     * @brief CDialog::createDialog
     * Create a dialog box with an image background
     * @param *screen CEsWorldScreen pointer to screen
     * @param background string the background image to use
     * @param x int x position
     * @param y int y position
     * @param clip SDL_Rect the clip coordinants of the background image
     */
    void createImageDialog(CEsWorldScreen *screen, std::string background,
                           int x, int y, SDL_Rect clip);
    /**
     * @brief CDialog::createBasicDialog
     * @param *screen CEsWorldScreen pointer to screen
     * @param x int x position
     * @param y int y position
     * @param width int width
     * @param height int height
     */
    void createBasicDialog(CEsWorldScreen *screen, int x, int y,
                           int width, int height,
                           SDL_Color color = {0xFF, 0xFF, 0xFF, 0xFF});
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
    void createTextDialog(CEsWorldScreen *screen, int x, int y,
                          int width, int height,
                          const std::string *text,
                          SDL_Color fillColor = {0xFF, 0xFF, 0xFF, 0xFF},
                          SDL_Color textColor = {0x00, 0x00, 0x00, 0x00});
    /**
     * @brief showDialog
     */
    void showDialog();
    /**
     * @brief closeDialog
     */
    void closeDialog(void);
    /**
     * @brief getWidth
     * @return int m_nWidth
     */
    int getWidth(void) const { return m_nWidth; }
    /**
     * @brief getHeight
     * @return int m_nHeight
     */
    int getHeight(void) const { return m_nHeight; }
private:
    void setWidth(int width) { m_nWidth = width; }
    void setHeight(int height) { m_nHeight = height; }
    int m_nWidth;
    int m_nHeight;
    int m_nPositionX;
    int m_nPositionY;
    bool m_bState;
};

#endif // CDIALOG_H
