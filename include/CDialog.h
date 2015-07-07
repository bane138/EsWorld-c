#ifndef CDIALOG_H
#define CDIALOG_H
#include <string>
#include <SDL.h>
#include "tools.h"

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
    CDialog(void);
    /* Destructor */
    ~CDialog(void);
    /* createDialog build a dialog box. This will probaly
     * have several overriden versions depending on the types
     * of dialogs we come up with.
     */
    void createDialog(int x, int y, int width, int height, const char *title);
    /* showDialog display at x y */
    bool showDialog(int x, int y);
    bool closeDialog(void);
    int getWidth(void) const { return m_nWidth; }
    int getHeight(void) const { return m_nHeight; }
private:
    void setWidth(int width) { m_nWidth = width; }
    void setHeight(int height) { m_nHeight = height; }
    SDL_Window *sdl_wWindow;
    SDL_Renderer *sdl_rRenderer;

    int m_nWidth;
    int m_nHeight;
    int m_nPositionX;
    int m_nPositionY;
    int m_nState;
};

#endif // CDIALOG_H
