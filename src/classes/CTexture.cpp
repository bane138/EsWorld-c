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
bool CTexture::loadFromFile(CEsWorldScreen *screen, std::string filePath,
                            Uint8 red, Uint8 green, Uint8 blue)
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
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format,
                                                            red, green, blue));
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
 * @brief CTexture::loadFromRenderedText
 * @param screen
 * @param textureText
 * @param textColor
 */
#ifdef _SDL_TTF_H
bool CTexture::loadFromRenderedText(CEsWorldScreen *screen, TTF_Font *font,
                               std::string textureText, SDL_Color textColor)
{
    // Get rid of existing texture
    free();

    // Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(),
                                                    textColor);
    if(textSurface == nullptr) {
        std::cout << "TTF_RenderText_Solid error" << SDL_GetError() << std::endl;
    } else {
        // Create texture from surface pixels
        m_sdlTexture = SDL_CreateTextureFromSurface(screen->getRenderer(), textSurface);
        if(m_sdlTexture == nullptr) {
            std::cout << "SDL_CreateTextureFromSurface error" << SDL_GetError() << std::endl;
        } else {
            // Get image dimensions
            m_nWidth = textSurface->w;
            m_nHeight = textSurface->h;
        }
        // Get rid of the old surface
        SDL_FreeSurface(textSurface);
    }

    return m_sdlTexture != nullptr;
}
#endif
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

/**
 * @brief CTexture::setAlpha
 * Modulate alpha (transparency)
 * @param alpha
 */
void CTexture::setAlpha(Uint8 alpha)
{
    // Modulate texture alpha
    SDL_SetTextureAlphaMod(m_sdlTexture, alpha);
}

void CTexture::setBlendMode(SDL_BlendMode blending)
{
    // Set blending function
    SDL_SetTextureBlendMode(m_sdlTexture, blending);
}

/**
 * @brief CTexture::setColor
 * Color modulation
 * @param red
 * @param gree
 * @param blue
 */
void CTexture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
    // Modulate texture
    SDL_SetTextureColorMod(m_sdlTexture, red, green, blue);
}

void CTexture::render(CEsWorldScreen *screen, int x, int y, SDL_Rect *clip,
                      double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    // Set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, m_nWidth, m_nHeight };
    if(clip) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(screen->getRenderer(), m_sdlTexture, clip, &renderQuad,
                   angle, center, flip);
}
