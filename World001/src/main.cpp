#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "CGame.h"

using namespace std;

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char **argv[])
{
    CGame game;
    game.startGame();
    if(game.isGameRunning()) {
        std::cout << "The game is running!" << endl;
    } else {
        std::cout << "The game is not running." << endl;
    }

    /*SDL_Color color = {255, 255, 255, 255};
    //SDL_Texture *background = loadTexture(resourcePath + "background.png", sdlRenderer);
    //SDL_Texture *image = loadTexture(resourcePath + "color_sheet.png", sdlRenderer);
    SDL_Texture *image = renderText("TTF fonts are cool!", resourcePath + "sample.ttf",
                                    color, 64, sdlRenderer);
    if(image == nullptr) {
        cleanup(sdlRenderer, sdlWindow);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    /*if(background == nullptr || image == nullptr) {
        cleanup(background, imagRenderer, sdlWindow);
        IMG_Quit();
        SDL_Quit();e, sdl
        return 1;
    }

    int xTiles = SCREEN_WIDTH / TILE_SIZE;
    int yTiles = SCREEN_HEIGHT / TILE_SIZE;

    for(int i = 0; i < xTiles * yTiles; ++i) {
        int x = i % xTiles;
        int y = i / xTiles;
        renderTexture(background, sdlRenderer, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
    }*/
    /*int bW, bH;
    SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
    renderTexture(background, sdlRenderer, 0, 0);
    renderTexture(background, sdlRenderer, bW, 0);
    renderTexture(background, sdlRenderer, 0, bH);
    renderTexture(background, sdlRenderer, bW, bH);*/

    //int iW = 100, iH = 100;
    /*int iW, iH;
    SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
    int x = SCREEN_WIDTH / 2 - iW / 2;
    int y = SCREEN_HEIGHT / 2 - iH / 2;
    //renderTexture(image, sdlRenderer, x, y);

    // Setup the clips for out image
    SDL_Rect clips[4];
    for(int i = 0; i < 4; ++i) {
        clips[i].x = i / 2 * iW;
        clips[i].y = i % 2 * iH;
        clips[i].w = iW;
        clips[i].h = iH;
    }

    // specify the clip to start with
    int useClip = 0;

    SDL_Event e;
    bool quit = false;
    while(!quit) {
        // Read user input and handle
        while(SDL_PollEvent(&e)) {
            // If the user closes the window
            if(e.type == SDL_QUIT) {
                quit = true;
            }
            // If the user presses keys 1 - 4
            // select different clip sections or
            // quit on escape
            if(e.type == SDL_KEYDOWN) {
                switch(e.key.keysym.sym) {
                    case SDLK_1:
                        useClip = 0;
                        break;
                   case SDLK_2:
                        useClip = 1;
                        break;
                   case SDLK_3:
                        useClip = 2;
                        break;
                   case SDLK_4:
                        useClip = 3;
                        break;
                   case SDLK_ESCAPE:
                        quit = true;
                        break;
                   default:
                        break;
                }
            }

            // If the user clickes the mouse
            /*if(e.type == SDL_MOUSEBUTTONDOWN) {
                quit = true;
            }
        }
        // Render screen
        SDL_RenderClear(sdlRenderer);
        renderTexture(image, sdlRenderer, x, y); //, &clips[useClip]
        SDL_RenderPresent(sdlRenderer);
    }

    /*SDL_RenderPresent(sdlRenderer);
    SDL_Delay(3000);*/

    /*cleanup(image, sdlRenderer, sdlWindow);
    SDL_Quit();*/
    return 0;
}

