#ifndef ESWORLDSCREEN_H
#define ESWORLDSCREEN_H
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class CEsWorldScreen
{
public:
    /* Default Constructor */
    CEsWorldScreen(void);
    /* Destructor */
    ~CEsWorldScreen(void);
    /* Setup screen */
    bool setupScreen(void);
    /* Create screen */
    void createScreen(int x, int y);
    /* Accessor functions */
    int getWidth(void) const { return m_nWidth; }
    int getHeight(void) const { return m_nHeight; }
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
    std::string *sResourcePath;
    SDL_Window *sdl_wWindow;
    SDL_Renderer *sdl_rRenderer;
    SDL_Surface *sdl_sSurface;
    SDL_Texture *sdl_tBackground;
};

#endif // ESWORLDSCREEN_H

