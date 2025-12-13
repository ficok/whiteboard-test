cmake_minimum_required(VERSION 3.16)

project(whiteboard-test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(DATA_SOURCES
    # models
    data/model/Document.hpp        data/model/Document.cpp
    data/model/Page.hpp            data/model/Page.cpp
    data/model/DrawableElement.hpp data/model/DrawableElement.cpp
    data/model/Request.hpp
    data/model/Response.hpp
    data/model/ResponseBase.hpp

    # backend
    data/backend/Backend.hpp
    data/backend/LocalBackend.hpp   data/backend/LocalBackend.cpp
    data/backend/BackendManager.hpp data/backend/BackendManager.cpp
)

set(VIEW_SOURCES
    view/View.hpp         view/View.cpp
    view/PageScene.hpp    view/PageScene.cpp
    view/DrawableItem.hpp view/DrawableItem.cpp
)

set(CONTROLLER_SOURCES
    controller/Controller.hpp  controller/Controller.cpp
    controller/Tool.hpp
    controller/ToolManager.hpp controller/ToolManager.cpp
)

set(COMMANDS_SOURCES
    commands/Command.hpp        commands/Command.cpp
    commands/CommandHistory.hpp commands/CommandHistory.cpp
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ${DATA_SOURCES}
        ${VIEW_SOURCES}
        ${CONTROLLER_SOURCES}
        ${COMMANDS_SOURCES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(whiteboard-test
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET whiteboard-test APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(whiteboard-test SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(whiteboard-test
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(whiteboard-test
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/data
        ${CMAKE_CURRENT_SOURCE_DIR}/data/model
        ${CMAKE_CURRENT_SOURCE_DIR}/data/backend
        ${CMAKE_CURRENT_SOURCE_DIR}/view
        ${CMAKE_CURRENT_SOURCE_DIR}/controller
        ${CMAKE_CURRENT_SOURCE_DIR}/commands
)
target_link_libraries(whiteboard-test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.whiteboard-test)
endif()
set_target_properties(whiteboard-test PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS whiteboard-test
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(whiteboard-test)
endif()
