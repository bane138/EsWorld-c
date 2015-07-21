#include "CTexture.h"

/**
 * @brief CTexture::CTexture
 */
CTexture::CTexture(void)
{
    m_sdlTexture = NULL;
    m_nWidth = 0;
    m_nHeight = 0;
}

/**
 * @brief CTexture::~CTexture
 */
CTexture::~CTexture(void)
{
    /* Deallocate */
    free();
}

/**
 * @brief CTexture::loadFromFile
 * Load texture from file, this uses a color key probably overload this
 * @param CEsWorldScreen screen
 * @param string filePath
 * @return bool
 */
bool CTexture::loadFromFile(CEsWorldScreen *screen, std::string filePath)
{
    // Get rid of any preexisting texture
    free();

    // The final texture
    SDL_Texture* newTexture = NULL;

    // Load the image at the specified path
    SDL_Surface* loadedSurface = IMG_Load(filePath.c_str());
    if(loadedSurface == NULL) {
        std::cout << "IMG_Load error: " << SDL_GetError() << std::endl;
    } else {
        // Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        newTexture = SDL_CreateTextureFromSurface(screen->getRenderer(), loadedSurface);
    }

    if(newTexture == NULL) {
        std::cout << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
    } else {
        m_nWidth = loadedSurface->w;
        m_nHeight = loadedSurface->h;
    }

    // Free the loaded surface
    SDL_FreeSurface(loadedSurface);

    m_sdlTexture = newTexture;
    return m_sdlTexture != NULL;
}

/**
 * @brief CTexture::free
 */
void CTexture::free(void)
{
    if(m_sdlTexture != NULL) {
        SDL_DestroyTexture(m_sdlTexture);
        m_sdlTexture = NULL;
        m_nWidth = 0;
        m_nHeight = 0;
    }
}

void CTexture::render(CEsWorldScreen *screen, int x, int y)
{
    // Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, m_nWidth, m_nHeight };
    SDL_RenderCopy(screen->getRenderer(), m_sdlTexture, NULL, &renderQuad);
}
