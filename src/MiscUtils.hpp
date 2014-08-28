#ifndef MISCUTILS_HPP
#define MISCUTILS_HPP

#include <time.h>
#include <string>
#include <sstream>

//Used to suppress "Unused variable" warnings
#define MON_Internal_UnusedStringify(macro_arg_string_literal) #macro_arg_string_literal
#define MarkUnused(macro_arg_parameter) _Pragma(MON_Internal_UnusedStringify(unused(macro_arg_parameter)))

namespace MiscUtils {
    int delay(long milliseconds);
    int stringToInt(std::string input);
    std::string executeGetOutput(std::string cmd);
    void execute(std::string cmd);
    void replaceAll(std::string& str, const std::string& from, const std::string& to);
    std::string replaceAllGiveString(std::string str, const std::string& from, const std::string& to);
}

#endif
