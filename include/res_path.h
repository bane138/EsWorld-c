#ifndef RES_PATH_H
#define RES_PATH_H

#include <iostream>
#include <string>
#include <SDL.h>

/*
 * Get the resource path located in res/subdir
 * It's assumed the project directory is structured like:
 * bin/
 *  the executable
 * res/
 *  dir1/
 *  dir2/
 *
 * Paths returned will be main/res/dir1
 */

std::string getResourcePath(const std::string &subDirectory = "") {
    /*
     * Chose a path seperatory correctly depending on the
     */
#ifdef _WIN32
    const char PATH_SEPERATOR = '\\';
#else
    const char PATH_SEPERATOR = '/';
#endif

    /*
     * This holds the base resource path: project/res
     * We give it static lifetime so that we only need to call
     * SDL_GetBasePath once to get the execution path
     */
    static std::string baseResource;
    if(baseResource.empty()) {
        // SDL_GetBasePath will return NULL if something went wrong
        char *basePath = SDL_GetBasePath();
        if(basePath) {
            baseResource = basePath;
            SDL_free(basePath);
        } else {
            std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
            return "";
        }
        // replace the last /bin with /res to get the resource path
        size_t pos = baseResource.rfind("bin");
        baseResource = baseResource.substr(0, pos) + "res" + PATH_SEPERATOR;
    }
    // If we want a specific subdirectory path in the resource directory
    // append it to the base path.
    return subDirectory.empty() ? baseResource : baseResource + subDirectory + PATH_SEPERATOR;
}

#endif // RES_PATH_H
