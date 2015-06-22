#include <iostream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "res_path.h"
#include "cleanup.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int TILE_SIZE = 40;

/**
  * Log an SDLK error with some error message to the output stream of our choice
  * @param outputstream the output stream to write the message to
  * @param message the error message to write, format will be message error: SDL_GetError
  */
void logSDLError(std::ostream &outputstream, const std::string &message) {
    outputstream << message << " error: " << SDL_GetError() << std::endl;
}

/**
  * Loads an image into a texture on the rendering  device
  * @param file The image file to load
  * @param renderer The renderer to load into
  * @return The loaded texture or nullptr if something went wrong
  */
SDL_Texture* loadTexture(const string &file, SDL_Renderer *renderer) {
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
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer,
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
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, SDL_Rect destination,
                   SDL_Rect *clip = nullptr) {
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
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y,
                   SDL_Rect *clip = nullptr) {
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
 * @brief main
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char **argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        logSDLError(std::cout, "SDL_Init");
        return 1;
    }

    SDL_Window *sdlWindow = SDL_CreateWindow("Hello World",
                                            100, 100,
                                            SCREEN_WIDTH, SCREEN_HEIGHT,
                                            SDL_WINDOW_SHOWN);
    if(sdlWindow == nullptr) {
        logSDLError(std::cout, "SDL_CreateWindow");
        SDL_Quit();
        return 1;
    }


    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1,
                                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(sdlRenderer == nullptr) {
        logSDLError(std::cout, "SDL_Renderer");
        SDL_Quit();
        return 1;
    }

    if((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        logSDLError(std::cout, "IMG_Init");
        SDL_Quit();
        return 1;
    }


    const std::string resourcePath = getResourcePath("World001");
    SDL_Texture *background = loadTexture(resourcePath + "background.png", sdlRenderer);
    SDL_Texture *image = loadTexture(resourcePath + "image2.png", sdlRenderer);
    if(background == nullptr || image == nullptr) {
        cleanup(background, image, sdlRenderer, sdlWindow);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    int xTiles = SCREEN_WIDTH / TILE_SIZE;
    int yTiles = SCREEN_HEIGHT / TILE_SIZE;

    for(int i = 0; i < xTiles * yTiles; ++i) {
        int x = i % xTiles;
        int y = i / xTiles;
        renderTexture(background, sdlRenderer, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
    }
    /*int bW, bH;
    SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
    renderTexture(background, sdlRenderer, 0, 0);
    renderTexture(background, sdlRenderer, bW, 0);
    renderTexture(background, sdlRenderer, 0, bH);
    renderTexture(background, sdlRenderer, bW, bH);*/

    int iW, iH;
    SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
    int x = SCREEN_WIDTH / 2 - iW / 2;
    int y = SCREEN_HEIGHT / 2 - iH / 2;
    //renderTexture(image, sdlRenderer, x, y);

    SDL_Event e;
    bool quit = false;
    while(!quit) {
        // Read user input and handle
        while(SDL_PollEvent(&e)) {
            // If the user closes the window
            if(e.type == SDL_QUIT) {
                quit = true;
            }
            // If the user presses any key (this doesnt work
            // use keycode for specific character)
            /*if(e.type == SDL_KEYDOWN) {
                quit = true;
            }*/
            // If the user clickes the mouse
            if(e.type == SDL_MOUSEBUTTONDOWN) {
                quit = true;
            }
        }
        // Render screen
        SDL_RenderClear(sdlRenderer);
        renderTexture(image, sdlRenderer, x, y);
        SDL_RenderPresent(sdlRenderer);
    }

    /*SDL_RenderPresent(sdlRenderer);
    SDL_Delay(3000);*/

    cleanup(background, image, sdlRenderer, sdlWindow);
    SDL_Quit();
    return 0;
}

