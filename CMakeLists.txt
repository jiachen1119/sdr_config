cmake_minimum_required(VERSION 3.10.0)
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

find_package(Threads)

AUX_SOURCE_DIRECTORY(.          SRC_LIST)
AUX_SOURCE_DIRECTORY(UI         SRC_LIST)
AUX_SOURCE_DIRECTORY(HackRF     SRC_LIST)
AUX_SOURCE_DIRECTORY(myQString  SRC_LIST)
AUX_SOURCE_DIRECTORY(Monitor    SRC_LIST)

add_executable(sdr_config  ${SRC_LIST})
add_subdirectory(Monitor)
target_link_libraries(sdr_config
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        monitoring_lib
        ${CMAKE_THREAD_LIBS_INIT}
        )
target_include_directories(sdr_config
        PUBLIC
        ${PROJECT_SOURCE_DIR}/Monitor
        ${CMAKE_THREAD_LIBS_INIT}
        )

