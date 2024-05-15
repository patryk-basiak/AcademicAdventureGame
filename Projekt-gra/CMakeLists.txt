cmake_minimum_required(VERSION 3.27)
project(GraCpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraCpp main.cpp)
set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)
FetchContent_MakeAvailable(SFML)

add_executable(game main.cpp
        Player.cpp
        Player.h
        Player.cpp
        ResourceManager.cpp
        objects/JumpPad.cpp
        objects/JumpPad.h
        objects/Collectable.cpp
        objects/Collectable.h
        Equipment.cpp
        Equipment.h
        Settings.cpp
        Settings.h
        objects/Pistol.cpp
        objects/Pistol.h
        objects/Wall.cpp
        objects/Wall.h
        objects/Coin.cpp
        objects/Coin.h
        objects/Entity.cpp
        objects/Entity.h
        objects/Bullet.cpp
        objects/Bullet.h
        Map.cpp
        Map.h
)
target_link_libraries(game sfml-graphics sfml-audio)
target_link_libraries(game fmt)
