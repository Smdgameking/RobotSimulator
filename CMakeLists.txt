cmake_minimum_required(VERSION 3.16)

project(RobotSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RobotSimulator

    main.cpp

    Engine/Screen.cpp
    Engine/Input.cpp
    Engine/Time.cpp

    Simulator/Grid.cpp
    Simulator/Node.cpp
    Simulator/Robot.cpp
    Simulator/AStar.cpp
    Simulator/TTS.cpp
)

target_include_directories(RobotSimulator PRIVATE
    Engine
    Simulator
)
