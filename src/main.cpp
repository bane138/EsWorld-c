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
    game.startGame();
    CEsWorldScreen screen = game.getScreen();    
    CDialog dialogBox1;
    CDialog dialogBox2;
    CDialog dialogBox3;
    CPlayer player;
    CTexture dude;
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
        dude.loadFromFile(&screen, screen.getResPath() + "dude.png");
        dude.render(&screen, 100, 100);
        SDL_RenderPresent(screen.getRenderer());
    }

    screen.deleteScreen();
    return 0;
}

