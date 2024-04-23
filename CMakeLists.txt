cmake_minimum_required(VERSION 3.27)
project(DinoProject)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)


add_executable(DinoProject main.cpp
        Player.cpp
        Player.h)
target_link_libraries(DinoProject sfml-graphics)
