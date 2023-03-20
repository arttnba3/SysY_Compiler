cmake_minimum_required(VERSION 3.20)
project(arttnba3_miniSysY_compiler)

set(CMAKE_CXX_STANDARD 17)

AUX_SOURCE_DIRECTORY(. SRC_DIRS)

set(CMAKE_CXX_STANDARD 17)
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("include")

add_subdirectory("scanner")
add_subdirectory("syntactic")

add_executable(A3Compiler main.cpp)

# Options for debugging only
# SET(CMAKE_BUILD_TYPE "Debug")
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

target_link_libraries(A3Compiler Scanner Syntactic)