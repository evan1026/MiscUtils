#ifndef MISCUTILS_HPP
#define MISCUTILS_HPP

#include <time.h>
#include <string>
#include <sstream>

int delay(long milliseconds);
int stringToInt(std::string input);
std::string executeGetOutput(std::string cmd);
void execute(std::string cmd);

#endif
