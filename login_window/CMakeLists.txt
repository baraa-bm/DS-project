cmake_minimum_required(VERSION 3.16)

project(MediQueueLoginLauncher VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_LIST_DIR}/..)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

qt_add_executable(appMediQueue_Login
    main_login.cpp
    logindialog.cpp
    logindialog.h
    userauth.cpp
    userauth.h
    ../application/user.cpp
    ../application/user.h
    ../mainwindow.cpp
    ../mainwindow.h
    ../mainWindow.ui
    ../resources.qrc
)

target_include_directories(appMediQueue_Login PRIVATE
    ..
    ../application
)

file(TO_CMAKE_PATH "${CMAKE_CURRENT_LIST_DIR}/../users.txt" MEDIQUEUE_USERS_FILE)
target_compile_definitions(appMediQueue_Login PRIVATE
    MEDIQUEUE_USERS_FILE="${MEDIQUEUE_USERS_FILE}"
)

target_link_libraries(appMediQueue_Login PRIVATE Qt6::Widgets)

set_target_properties(appMediQueue_Login PROPERTIES
    WIN32_EXECUTABLE TRUE
)

configure_file(${CMAKE_CURRENT_LIST_DIR}/../users.txt ${CMAKE_CURRENT_BINARY_DIR}/users.txt COPYONLY)
