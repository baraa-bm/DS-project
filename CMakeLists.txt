cmake_minimum_required(VERSION 3.10)
project(DS-project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(DataStructures application)

add_executable(main
    application/main.cpp
    application/manager.cpp
    application/persistence.cpp
    DataStructures/List.cpp
    DataStructures/priorityQueue.cpp
    DataStructures/queue.cpp
    DataStructures/task.cpp
    DataStructures/time.cpp
)