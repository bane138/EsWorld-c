#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "res_path.h"
#include "cleanup.h"
#include "tools.h"
#include "CEsWorldScreen.h"

/**
 * @brief CEsWorldScreen::CEsWorldScreen
 */
CEsWorldScreen::CEsWorldScreen(void)
{
    m_nWidth = 640;
    m_nHeight = 480;
}

/**
 * @brief CEsWorldScreen::~CEsWorldScreen
 */
CEsWorldScreen::~CEsWorldScreen(void)
{
    deleteScreen();
}

/**
 * @brief CEsWorldScreen::setupScreen
 * @return
 */
bool CEsWorldScreen::setupScreen(void)
{
    // SDL Init
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        logSDLError(std::cout, "SDL_Init");
        return false;
    }

    // TTF Init
    if(TTF_Init() != 0) {
        logSDLError(std::cout, "TTF_Init");
        return false;
    }

    // IMG Init
    if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        logSDLError(std::cout, "IMG_Init");
        SDL_Quit();
        return false;
    }

    // SDL Window
    this->sdl_wWindow = SDL_CreateWindow("EsWorld",
                                            100,100,
                                            640, 480,
                                            SDL_WINDOW_SHOWN);
    if(this->sdl_wWindow == nullptr) {
        logSDLError(std::cout, "SDL_CreateWindow");
        SDL_Quit();
        return false;
    }

    // SDL Renderer
    this->sdl_rRenderer = SDL_CreateRenderer(sdl_wWindow, -1,
                                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(this->sdl_rRenderer == nullptr) {
        logSDLError(std::cout, "SDL_Renderer");
        SDL_Quit();
        return false;
    }
}

/**
 * @brief CEsWorldScreen::deleteScreen
 */
void CEsWorldScreen::deleteScreen(void)
{
    cleanup(this->sdl_tBackground, this->sdl_rRenderer, this->sdl_wWindow);
}

/**
 * @brief CEsWorldScreen::createScreen
 * Load texture and render the screen
 */
void CEsWorldScreen::createScreen(int x, int y)
{
    this->sdl_tBackground = this->loadTexture(getResourcePath("World001") + "background.png",
                                              this->sdl_rRenderer);
    SDL_RenderClear(this->sdl_rRenderer);
    this->renderTexture(this->sdl_tBackground, this->sdl_rRenderer, x, y);
    SDL_RenderPresent(this->sdl_rRenderer);
}

/**
  * CEsWorldScreen::createText
  * @param std::string text the text
  */
void CEsWorldScreen::createText(std::string &text)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Texture *textToRender = this->renderText(text, getResourcePath("World001") + "sample.ttf",
                                                 color, 32, this->sdl_rRenderer);
    SDL_RenderClear(this->sdl_rRenderer);
    this->renderTexture(textToRender, this->sdl_rRenderer, 100, 100);
    SDL_RenderPresent(this->sdl_rRenderer);
}

/**
  * Loads an image into a texture on the rendering  device
  * @param file The image file to load
  * @param renderer The renderer to load into
  * @return The loaded texture or nullptr if something went wrong
  */
SDL_Texture* CEsWorldScreen::loadTexture(const std::string &file, SDL_Renderer *renderer) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
    if(texture == nullptr) {
        logSDLError(std::cout, "IMG_LoadTexture");
    }
    return texture;
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param w The width of the texture to draw
* @param h The height of the texture to draw
*/
void CEsWorldScreen::renderTexture(SDL_Texture *texture, SDL_Renderer *renderer,
                         int x, int y, int w, int h) {
    // Setup the destination rectangle to be at the position we want
    SDL_Rect destination;
    destination.x = x;
    destination.y = y;
    destination.w = w;
    destination.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &destination);
}

/**
  * Draw an SDL_Texture to an SDL_Renderer at some destination rect.
  * takeing a clip of the texture if desiredct
  * @param texture the source texture we want to draw
  * @param renderer the renderer we want to draw to
  * @param destination the destination rectangle to render the texture to
  * @param clip the sub-section of the the texure to draw (clipping rect)
  * default of nullptr draws the entire texture
  */
void CEsWorldScreen::renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect destination,
                   SDL_Rect *clip) {
    SDL_RenderCopy(renderer, texture, clip, &destination);
}

/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height and taking a clip of the texture if
* desired. If a clip is passed, the clip's width and height will be used
* instead of the texture's
* @param texture The source texture we want to draw
* @param renderer The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param clip The sub-section of the texture to draw (clipping rect)
* default of nullptr draws the entire texture
*/
void CEsWorldScreen::renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y,
                   SDL_Rect *clip) {
    SDL_Rect destination;
    destination.x = x;
    destination.y = y;
    if(clip != nullptr) {
        destination.w = clip->w;
        destination.h = clip->h;
    } else {
        SDL_QueryTexture(texture, NULL, NULL, &destination.w, &destination.h);
    }

    renderTexture(texture, renderer, destination, clip);
}

/**
  * Render the message we want to display to a texture for rendering
  * @param message The message we want to display
  * @param fontFile The font we want to use
  * @param color The color for the text
  * @param fontSize The size of the text
  * @param renderer The renderer
  * @return An SDL_Texture containing the message or nullptr if something went wrong
  */
SDL_Texture* CEsWorldScreen::renderText(const std::string &message, const std::string &fontFile,
                        SDL_Color color, int fontSize, SDL_Renderer *renderer) {
    // Open the font
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if(font == nullptr) {
        logSDLError(std::cout, "TTF_OpenFont");
        return nullptr;
    }

    // We need to first render to a surface as that's what TTF_RenderText returns.
    // Then load that surface into a texture
    SDL_Surface *surface = TTF_RenderText_Blended(font, message.c_str(), color);
    if(surface == nullptr) {
        logSDLError(std::cout, "TTF_RenderText_Blended");
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == nullptr) {
        logSDLError(std::cout, "SDL_CreateTextureFromSurface");
        return nullptr;
    }

    // Clean up surface and font
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    return texture;
}