#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "CGame.h"
#include "CDialog.h"
#include "CPlayer.h"
#include "CTexture.h"

#include <time.h>


using namespace std;

// helper for animation put this in a sprite class eventually
/*bool loadMedia(CTexture *sprite, SDL_Rect *spriteClips)
{
    // success flag
    bool success = true;

    // Load sprite sheet texture
    if(!sprite->loadFromFile(&screen, screen.getResPath() + "dude_walking_left.png")) {
        std::cout << "IMG_Load error: " << SDL_GetError() << std::endl;
        success = false;
    } else {
        // Set sprite clips
        spriteClips[0].x = 0;
        spriteClips[0].y = 0;
        spriteClips[0].w = 64;
        spriteClips[0].h = 205;

        spriteClips[1].x = 64;
        spriteClips[1].y = 0;
        spriteClips[1].w = 64;
        spriteClips[1].h = 205;

        spriteClips[2].x = 128;
        spriteClips[2].y = 0;
        spriteClips[2].w = 64;
        spriteClips[2].h = 205;

        spriteClips[3].x = 256;
        spriteClips[3].y = 0;
        spriteClips[3].w = 196;
        spriteClips[3].h = 205;
    }

    return success;
}*/

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
    const int WALKING_ANIMATION_FRAMES = 4;
    SDL_Rect spriteClips[WALKING_ANIMATION_FRAMES];
    int frame = 0;
    double degrees = 0;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    CGame game;
    SDL_Event e;
    game.startGame();
    CEsWorldScreen screen = game.getScreen();    
    CDialog dialogBox1;
    CDialog dialogBox2;
    CDialog dialogBox3;
    TTF_Font *font = NULL;
    SDL_Color fontColor = { 0, 0, 0, 0 };
    CPlayer player;
    CTexture sprite;
    CTexture arrow;
    CTexture text;
    // may want a good way to load fonts posibly a text class that uses
    // CTexture to render it
    std::string fontFile = screen.getResPath() + "sample.ttf";
    font = TTF_OpenFont(fontFile.c_str(), 28);

    text.loadFromRenderedText(&screen, font, "Here is my text", fontColor);

    arrow.loadFromFile(&screen, screen.getResPath() + "arrow.png");
    // for animation
    if(!sprite.loadFromFile(&screen, screen.getResPath() + "dude_walking_left.png",
                            0, 0xFF, 0xFF)) {
        std::cout << "IMG_Load error: " << SDL_GetError() << std::endl;
    } else {
        // Set sprite clips
        spriteClips[0].x = 0;
        spriteClips[0].y = 0;
        spriteClips[0].w = 64;
        spriteClips[0].h = 205;

        spriteClips[1].x = 64;
        spriteClips[1].y = 0;
        spriteClips[1].w = 64;
        spriteClips[1].h = 205;

        spriteClips[2].x = 128;
        spriteClips[2].y = 0;
        spriteClips[2].w = 64;
        spriteClips[2].h = 205;

        spriteClips[3].x = 256;
        spriteClips[3].y = 0;
        spriteClips[3].w = 196;
        spriteClips[3].h = 205;
    }
    // for animation
    player.setXPosition(100);
    player.setYPosition(100);
    time_t starttime;
    time(&starttime);
    time_t timepassed;
    static int frames = 0;
    static bool first = true;
    static float fps = 0.0f;
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
                    case SDLK_w:
                        player.setYPosition(player.getYPosition() - 10);
                        break;
                    case SDLK_s:
                        player.setYPosition(player.getYPosition() + 10);
                        break;
                    case SDLK_d:
                        player.setXPosition(player.getXPosition() + 10);
                        break;
                    case SDLK_a:
                        player.setXPosition(player.getXPosition() - 10);
                        break;
                    case SDLK_RIGHT:
                        degrees -= 60;
                        break;
                    case SDLK_LEFT:
                        degrees += 60;
                        break;
                    case SDLK_h:
                        flipType = SDL_FLIP_HORIZONTAL;
                        break;
                    case SDLK_v:
                        flipType = SDL_FLIP_VERTICAL;
                        break;
                    case SDLK_n:
                        flipType = SDL_FLIP_NONE;
                        break;
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
        SDL_RenderClear(screen.getRenderer());
        screen.drawScreen("background.png", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        //screen.drawScreen("color_sheet.png", 10, 10, clip);
        screen.drawText(to_string(fps), 10, 10);
        screen.drawText(to_string(game.getLevel()), 580, 10);
        player.drawPlayer(&screen);
        SDL_Rect* currentClip = &spriteClips[frame/4];
        //sprite.setBlendMode(SDL_BLENDMODE_BLEND);
        //sprite.setColor(0, 0, 255);
        //sprite.setAlpha(50);
        sprite.render(&screen,(SCREEN_WIDTH / 2) - (currentClip->w / 2),
                      (SCREEN_HEIGHT / 2) - (currentClip->h / 2), currentClip);
        arrow.render(&screen,
                     300, 200,
                     NULL, degrees, NULL, flipType);
        text.render(&screen, 10, 400);
        SDL_RenderPresent(screen.getRenderer());
        frame++;
        if(frame / 4 >= WALKING_ANIMATION_FRAMES) {
            frame = 0;
        }
    }

    screen.deleteScreen();
    return 0;
}

