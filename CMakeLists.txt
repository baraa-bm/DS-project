cmake_minimum_required(VERSION 3.16)

project(Patient_Manager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()


file(GLOB_RECURSE SOURCES
    application/*.cpp
    DataStructures/*.cpp
    login_window/*.cpp
)

file(GLOB_RECURSE HEADERS
    application/*.h
    DataStructures/*.h
    login_window/*.h
    mainwindow.h
)

qt_add_executable(appPatient_Manager
    ${SOURCES}
    ${HEADERS}
    mainwindow.cpp
    mainwindow.ui
    resources.qrc    
)

target_link_libraries(appPatient_Manager
    PRIVATE Qt6::Widgets
)

target_include_directories(appPatient_Manager PRIVATE
    .
    application
    DataStructures
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/appPatient_Manager_autogen/include
)

# qt_add_qml_module(appPatient_Manager
#     URI Patient_Manager
#     QML_FILES
#         Main.qml
# )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPatient_Manager PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPatient_Manager
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE FALSE
)

install(TARGETS appPatient_Manager
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
