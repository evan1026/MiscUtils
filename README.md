MiscUtils
=========

A bunch of miscilanious utilities mostly for my own use but also free for others to use.

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

Usage
=====

Available functions:

    int delay(long milliseconds); //Returns the return of nanosleep().
                                  //See that documentation for return values.
