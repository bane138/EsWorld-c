#ifndef ESWORLDSCREEN_H
#define ESWORLDSCREEN_H
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define RESOURCE_PATH "World001"

class CEsWorldScreen
{
public:
    /* Default Constructor */
    CEsWorldScreen(void);
    /* Destructor */
    ~CEsWorldScreen(void);
    /* Setup screen */
    bool setupScreen(void);
    /* Draw screen */
    void drawScreen(const std::string &image, int x, int y, int w, int h);
    void drawScreen(const std::string &image, SDL_Rect destination, SDL_Rect clip);
    void drawScreen(const std::string &image, int x, int y, SDL_Rect clip);
    /* Create text */
    void drawText(const std::string &text, int x, int y);
    /* Accessor functions */
    int getWidth(void) const { return m_nWidth; }
    int getHeight(void) const { return m_nHeight; }
    SDL_Renderer* getRenderer(void) { return m_sdlRenderer; }
    std::string getResPath(void);
    /* Delete screen */
    void deleteScreen(void);
private:
    /* Load SDL texture */
    SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *renderer);
    /* SDL Render texture methods */
    void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer,
                             int x, int y, int w, int h);
    void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect destination,
                       SDL_Rect *clip = nullptr);
    void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y,
                       SDL_Rect *clip = nullptr);
    /* SDL render text method */
    SDL_Texture* renderText(const std::string &message, const std::string &fontFile,
                            SDL_Color color, int fontSize, SDL_Renderer *renderer);

    int m_nWidth;
    int m_nHeight;
    SDL_Window *m_sdlWindow;
    SDL_Renderer *m_sdlRenderer;
    SDL_Texture *m_tBackground;
};

#endif // ESWORLDSCREEN_H

