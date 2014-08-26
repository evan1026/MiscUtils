#include <iostream>
#include "MiscUtils.hpp"

int delay(long milliseconds){
    struct timespec tim,tim2;
    tim.tv_sec = milliseconds / 1000;
    tim.tv_nsec = (milliseconds % 1000) * 1000000;
    return nanosleep(&tim,&tim2);
}

int stringToInt(std::string input){
    std::stringstream data(input);
    int output;
    data >> output;
    return output;
}

std::string executeGetOutput(std::string cmd) {
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL) result += buffer;
    }
    pclose(pipe);
    return result;
}

void execute(std::string cmd){
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        std::cout << "Error executing command: \"" << cmd << "\"" << std::endl;
        exit(1);
    }
    pclose(pipe);
}
