cmake_minimum_required(VERSION 3.14)
project(GD)

set(CMAKE_CXX_FLAGS " -std=c++17")
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/StudentFiles/Student/SFML-2.5.1/lib/cmake/SFML)

set(SOURCE_FILES main.cpp App.cpp App.h Level.cpp Level.h Player.cpp Player.h StateMachine.cpp StateMachine.h State.cpp State.h DrawGroup.cpp DrawGroup.h LevelState.cpp LevelState.h globals.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics)