cmake_minimum_required(VERSION 2.8)

project(MiscUtils)

set(SOURCE_DIR "src")
set(MiscUtils_VERSION_MAJOR 2)
set(MiscUtils_VERSION_MINOR 0)
set(MiscUtils_VERSION_PATCH 0)

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

add_library(MiscUtils SHARED ${SOURCE_DIR}/MiscUtils.cpp)
SET_TARGET_PROPERTIES(MiscUtils PROPERTIES VERSION ${MiscUtils_VERSION_MAJOR}.${MiscUtils_VERSION_MINOR}.${MiscUtils_VERSION_PATCH})

INSTALL(FILES ${SOURCE_DIR}/MiscUtils.hpp DESTINATION include/MiscUtils)
INSTALL(TARGETS MiscUtils DESTINATION lib EXPORT FindMiscUtils)
INSTALL(EXPORT FindMiscUtils DESTINATION share/MiscUtils)
