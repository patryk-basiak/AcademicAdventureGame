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
        MapTypes.cpp
        MapTypes.h
        objects/Door.cpp
        objects/Door.h
        objects/Bed.cpp
        objects/Bed.h
        objects/Computer.cpp
        objects/Computer.h
        objects/Interactable.cpp
        objects/Interactable.h
        FPS.h
        objects/Icons.cpp
        objects/Icons.h
        objects/GoogleIcon.cpp
        objects/TeamsIcons.cpp
        HUD.cpp
        HUD.h
        Game.cpp
        Game.h
        DialogElement.cpp
        DialogElement.h
        objects/Wardrobe.cpp
        objects/Wardrobe.h
        objects/Chest.h
        objects/Chest.cpp
        objects/OakTree.cpp
        objects/OakTree.h
        objects/OakLeaves.cpp
        objects/OakLeaves.h
        DecisionElement.cpp
        DecisionElement.h
        objects/UniCard.cpp
        objects/UniCard.h
        objects/WildBoar.cpp
        objects/WildBoar.h
        objects/Kiosk.cpp
        objects/Kiosk.h
        objects/Health.cpp
        objects/Health.h
        objects/TimeIncreaser.cpp
        objects/TimeIncreaser.h
        objects/Wizard.cpp
        objects/Wizard.h
        objects/Car.cpp
        objects/Car.h
        objects/Shop.cpp
        objects/Shop.h
        objects/CarWinch.cpp
        objects/CarWinch.h
        objects/Grass.cpp
        objects/Grass.h
        objects/Dirt.cpp
        objects/Dirt.h
        objects/Brick.cpp
        objects/Brick.h
        objects/woodBlock.cpp
        objects/woodBlock.h
        objects/woodSlab.cpp
        objects/woodSlab.h
        objects/street.cpp
        objects/street.h
        objects/stone.cpp
        objects/stone.h
        objects/CarEnemy.cpp
        objects/CarEnemy.h
        ThrowableContainer.cpp
        ThrowableContainer.h
        objects/CarWinchItem.cpp
        objects/CarWinchItem.h
        objects/classroomDoor.cpp
        objects/classroomDoor.h
        objects/Elevator.cpp
        objects/Elevator.h
        objects/Disk.cpp
        objects/Disk.h
        objects/ChatGptIcon.cpp
        objects/ChatGptIcon.h
        objects/ComputerBoss.cpp
        objects/ComputerBoss.h
        objects/Shotgun.cpp
        objects/Shotgun.h
        objects/smallComputers.cpp
        objects/smallComputers.h
        objects/AssultRiffle.cpp
        objects/AssultRiffle.h
        Menu.cpp
        Menu.h
)
target_link_libraries(game sfml-graphics sfml-audio)
target_link_libraries(game fmt)
