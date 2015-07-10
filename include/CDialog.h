#ifndef CDIALOG_H
#define CDIALOG_H
#include <string>
#include <SDL.h>
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
    /* createDialog build a dialog box. This will probaly
     * have several overriden versions depending on the types
     * of dialogs we come up with.
     */
    void setScreen(CEsWorldScreen *screen);
    void createDialog(const std::string background, int x, int y, int width, int height);
    /* showDialog display at x y */
    bool showDialog();
    bool closeDialog(void);
    int getWidth(void) const { return m_nWidth; }
    int getHeight(void) const { return m_nHeight; }
private:
    void setWidth(int width) { m_nWidth = width; }
    void setHeight(int height) { m_nHeight = height; }
    CEsWorldScreen *m_oScreen;
    SDL_Rect *m_recDestination;
    SDL_Rect *m_recClip;
    int m_nWidth;
    int m_nHeight;
    int m_nPositionX;
    int m_nPositionY;
    int m_nState;
};

#endif // CDIALOG_H
