#ifndef CTEXTURE_H
#define CTEXTURE_H

#include <string>
#include <SDL.h>
#include <SDL_image.h>
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
    bool loadFromFile(CEsWorldScreen *screen, std::string filePath);
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
    void render(CEsWorldScreen *screen, int x, int y);
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
