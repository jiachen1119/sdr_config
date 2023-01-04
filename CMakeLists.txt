cmake_minimum_required(VERSION 3.24)
project(sdr_config)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(sdr_config main.cpp UI/sdr_windows.cpp UI/sdr_windows.h UI/sdr_windows.ui HackRF/HackRF.cpp HackRF/HackRF.h myQString/myQString.cpp myQString/myQString.h)
target_link_libraries(sdr_config
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

