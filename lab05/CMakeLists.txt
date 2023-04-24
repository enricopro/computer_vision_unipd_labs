# HOW TO BUILD:
# Follow the steps below to build the project: (assuming you are starting from the root folder of the project)
# 1. mkdir build && cd build
# 2. cmake ../
# 3. cmake --build .
# The different executables will be available in the build folder as "exec_task1", "exec_task2", etc.

cmake_minimum_required(VERSION 3.5)

project(Lab05
VERSION 1.0
DESCRIPTION "Lab05 - Computer Vision"
LANGUAGES CXX)

find_package(OpenCV 4 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

configure_file(street_scene.png street_scene.png COPYONLY)
configure_file(Asphalt-1.png Asphalt-1.png COPYONLY)
configure_file(Asphalt-2.png Asphalt-2.png COPYONLY)
configure_file(Asphalt-3.png Asphalt-3.png COPYONLY)
configure_file(robocup.jpg robocup.jpg COPYONLY)

add_executable(exec_task1 task1.cpp)
target_link_libraries(exec_task1 PRIVATE ${OpenCV_LIBS})

add_executable(exec_task2 task2.cpp)
target_link_libraries(exec_task2 PRIVATE ${OpenCV_LIBS})

add_executable(exec_task3 task3.cpp)
target_link_libraries(exec_task3 PRIVATE ${OpenCV_LIBS})

