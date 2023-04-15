# HOW TO BUILD:
# Follow the steps below to build the project: (assuming you are starting from the root folder of the project)
# 1. mkdir build && cd build
# 2. cmake ../
# 3. cmake --build .
# The different executables will be available in the build folder as "exec_task1", "exec_task2", etc.

cmake_minimum_required(VERSION 3.5)

project(Lab02
VERSION 1.0
DESCRIPTION "Lab04 - Computer Vision"
LANGUAGES CXX)

find_package(OpenCV 4 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

configure_file(street_scene.png street_scene.png COPYONLY)

add_executable(exec_task1 task1.cpp)
target_link_libraries(exec_task1 PRIVATE ${OpenCV_LIBS})

add_executable(exec_task3 task3.cpp)
target_link_libraries(exec_task3 PRIVATE ${OpenCV_LIBS})

add_executable(exec_task4 task4.cpp)
target_link_libraries(exec_task4 PRIVATE ${OpenCV_LIBS})

