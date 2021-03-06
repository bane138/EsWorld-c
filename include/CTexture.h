#ifndef CTEXTURE_H
#define CTEXTURE_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "CEsWorldScreen.h"

class CTexture
{
public:
    /**
     * @brief CTexture
     */
    CTexture(void);
    /**
     * @brief ~CTexture
     */
    ~CTexture(void);
    /**
     * @brief loadFromFile
     * Load texture from specified path
     * @param string filePath
     * @return bool
     */
#ifdef _SDL_TTF_H
    bool loadFromFile(CEsWorldScreen *screen, std::string filePath,
                      Uint8 red = 0xFF, Uint8 green = 0xFF, Uint8 blue = 0xFF);
#endif
    /**
     * @brief loadFromRenderedText
     * @param screen
     * @param textureText
     * @param textColor
     * @return
     */
    bool loadFromRenderedText(CEsWorldScreen *screen, TTF_Font *font,
                              std::string textureText, SDL_Color textColor);
    /**
     * @brief free
     * Free texture
     */
    void free(void);
    /**
     * @brief render
     * Render texture at specified location
     * @param int x
     * @param int y
     */
    void render(CEsWorldScreen *screen, int x, int y, SDL_Rect *clip = nullptr,
                double angle = 0.0, SDL_Point* center = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE);
    /**
     * @brief setAlpha
     * Set alpha (transparency)
     * @param alpha
     */
    void setAlpha(Uint8 alpha);
    /**
     * @brief setBlendMode
     * Set blending mode
     * @param blending
     */
    void setBlendMode(SDL_BlendMode blending);
    /**
     * @brief setColor
     * Color modulation
     * @param red
     * @param gree
     * @param blue
     */
    void setColor(Uint8 red, Uint8 gree, Uint8 blue);
    /**
     * @brief getWidth
     * @return int
     */
    int getWidth(void) const { return m_nWidth; }
    /**
     * @brief getHeight
     * @return int
     */
    int getHeight(void) const { return m_nHeight; }
private:
    /* The hardware texture */
    SDL_Texture *m_sdlTexture;
    int m_nWidth;
    int m_nHeight;
};

#endif // CTEXTURE_H
