cmake_minimum_required(VERSION 3.21)
project(CheckersNEwNEw)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(CheckersNEwNEw main.cpp players.cpp players.h board.cpp board.h game.cpp game.h)

set(SFML_DIR "C:\\Users\\rasba\\CLionProjects\\lib\\sfml\\GCC 7.3.0 MinGW (SEH) - 64-bit\\SFML-2.5.1\\lib\\cmake\\SFML")

target_link_libraries(CheckersNEwNEw sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 REQUIRED graphics network audio window system)