cmake_minimum_required(VERSION 3.19)
project(Stage1 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Stage1
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    equipo.h
    equipo.cpp
    cellular.h
    cellular.cpp
    territory.h
    territory.cpp
    territoryview.h
    territoryview.cpp
    equipo.h
    eloteltag.h
    eloteltag.cpp
    tablet.h
    tablet.cpp
)

target_link_libraries(Stage1
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS Stage1
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Stage1
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
