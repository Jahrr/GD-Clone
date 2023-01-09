cmake_minimum_required(VERSION 3.14)
project(GD)

set(CMAKE_CXX_FLAGS " -std=c++17")
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/StudentFiles/Student/SFML-2.5.1/lib/cmake/SFML)

set(SOURCE_FILES src/main.cpp src/App.cpp src/App.h src/Level.cpp src/Level.h src/Player.cpp src/Player.h src/StateMachine.cpp src/StateMachine.h src/State.cpp src/State.h src/DrawGroup.cpp src/DrawGroup.h src/LevelState.cpp src/LevelState.h src/globals.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics)