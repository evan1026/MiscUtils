MiscUtils
=========

A bunch of miscellaneous utilities mostly for my own use but also free for others to use.

Installation is easy:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make && sudo make install

That will install the necessary files. In order to use, just link up the header and library (/usr/local/include/MiscUtils.hpp and /usr/local/lib/libMiscUtils.so, respectively).
Note: The file paths only apply to Linux. I have no idea where it will install otherwise, so you'll have to find it yourself.

For CMake, you just need to add the module path:

    set(CMAKE_MODULE_PATH "/usr/local/share/MiscUtils/;${CMAKE_MODULE_PATH}")

then add the library:

    find_package(MiscUtils REQUIRED)
    target_link_libraries(${EXECUTABLE_NAME} MiscUtils)

Including the headers is just:

    #include <MiscUtils/MiscUtils.hpp>

Usage
=====

Available functions:

    MarkUnused(<variable>); //Not really sure what to do with the parameter here since it's a preprocessor thing
                            //It just surpresses warnings that a variable is unused

    int         MiscUtils::delay(long milliseconds);          //Returns the return of nanosleep().
                                                              //See that documentation for return values.
    int         MiscUtils::stringToInt(std::string input);    //Converts a string to an int
    std::string MiscUtils::executeGetOutput(std::string cmd); //Executes a command in the native shell and returns the output
    void        MiscUtils::execute(std::string cmd);          //Executes the command, this time ignoring output
    void        MiscUtils::replaceAll(std::string& str, const std::string& from, const std::string& to);          //Replaces all instances of 'from' with 'to' in 'str', modifying the original string
    std::string MiscUtils::replaceAllGiveString(std::string str, const std::string& from, const std::string& to); //Same as before, but leaves the original string intact and returns the new one
                                                                                                                  //This is useful when you want to plug some command's return right into it without storing it in between
    std::string getLinuxHomeFolder();        //Gets the string representation of the users home folder. Only works on linux
    bool        dirExists(std::string path); //Self-explainatory
