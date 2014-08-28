#include <iostream>
#include "MiscUtils.hpp"

int MiscUtils::delay(long milliseconds){
    struct timespec tim,tim2;
    tim.tv_sec = milliseconds / 1000;
    tim.tv_nsec = (milliseconds % 1000) * 1000000;
    return nanosleep(&tim,&tim2);
}

int MiscUtils::stringToInt(std::string input){
    std::stringstream data(input);
    int output;
    data >> output;
    return output;
}

std::string MiscUtils::executeGetOutput(std::string cmd) {
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

void MiscUtils::execute(std::string cmd){
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        std::cout << "Error executing command: \"" << cmd << "\"" << std::endl;
        exit(1);
    }
    pclose(pipe);
}

void MiscUtils::replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

std::string MiscUtils::replaceAllGiveString(std::string str, const std::string& from, const std::string& to){
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
