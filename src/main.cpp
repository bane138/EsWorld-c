#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "CGame.h"
#include "CDialog.h"

#include <time.h>

using namespace std;

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char **argv)
{
    /**
     * Game loop
     */
    CGame game;
    SDL_Event e;
    time_t starttime;
    time(&starttime);
    time_t timepassed;
    static int frames = 0;
    static bool first = true;
    static float fps = 0.0f;
    game.startGame();
    CEsWorldScreen *screen = game.getScreen();
    CDialog dialogBox;
    dialogBox.setScreen(screen);
    while(game.isGameRunning()) {
        time(&timepassed);
        if(first) {
            frames = 0;
            starttime = timepassed;
            first = false;
        }
        if(timepassed - starttime > 0.25 && frames > 10) {
            fps = (double) frames / (timepassed - starttime);
            starttime = timepassed;
            frames = 0;
        }

        std::cout << "The game is running!" << endl;
        while(SDL_PollEvent(&e)) {
            // If the user closes the window
            if(e.type == SDL_QUIT) {
                game.stopGame();
            }
            // quit on escape
            if(e.type == SDL_KEYDOWN) {
                switch(e.key.keysym.sym) {
                   /*case SDLK_1:
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
                        break;*/
                   case SDLK_ESCAPE:
                        game.stopGame();
                        break;
                   default:
                        break;
                }
            }
            if(e.type == SDL_MOUSEBUTTONDOWN) {
                game.stopGame();
            }
        }
        frames++;
        timepassed++;
        screen->drawScreen(0, 0, 640, 480);
        dialogBox.createDialog(10, 10, 50, 20);
        dialogBox.showDialog();
        //game.drawText(to_string(fps), 10, 10);
        //game.drawText(to_string(game.getLevel()), 580, 10);
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
    int useClip = 0;*/
    return 0;
}

