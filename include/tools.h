#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>

/**
  * Log an SDLK error with some error message to the output stream of our choice
  * @param outputstream the output stream to write the message to
  * @param message the error message to write, format will be message error: SDL_GetError
  */
void logSDLError(std::ostream &outputstream, const std::string &message) {
    outputstream << message << " error: " << SDL_GetError() << std::endl;
}

#endif // TOOLS_H
