#ifndef CLEANUP_H
#define CLEANUP_H

#include <utility>
#include "SDL.h"

/*
 * Recurse through a list of arguments to be cleaned up, cleaning up
 * the frist one in the list of each itteration
 */
template<typename T, typename... Args>
void cleanup(T *t, Args&&... args) {
    // clean up the first item in the list
    cleanup(t);
    // Recurse to clean up the remaining arguments
    cleanup(std::forward<Args>(args)...);
}

/*
 * These specializations server to free the passed argument and also provide the
 * base case for the recursive call above, eg. when args is only a single item
 * one of the specializations below will be called by
 * cleanup(std::forward<Args>(args)...), ending the recursion
 * We also make it safe to pass nullptrs to handle situations where we
 * don't want to bother finding out which values failed to load (and thus are null)
 * but rather just want to clean everything up and let cleanup sort it out.
 */
template<>
void cleanup<SDL_Window>(SDL_Window *win) {
    if(!win) {
        return;
    }
    SDL_DestroyWindow(win);
}

template<>
void cleanup<SDL_Renderer>(SDL_Renderer *ren) {
    if(!ren) {
        return;
    }
    SDL_DestroyRenderer(ren);
}

template<>
void cleanup<SDL_Texture>(SDL_Texture *tex) {
    if(!tex) {
        return;
    }
    SDL_DestroyTexture(tex);
}

template<>
void cleanup<SDL_Surface>(SDL_Surface *surf) {
    if(!surf) {
        return;
    }
    SDL_FreeSurface(surf);
}

#endif // CLEANUP_H
