find_package(Qt5 COMPONENTS PrintSupport REQUIRED)
add_library(myQchart_lib myQchart.cpp qcustomplot.cpp ../UI/qchart_window.cpp)
target_link_libraries(myQchart_lib
        PUBLIC
        Qt5::PrintSupport
        Qt5::Widgets)
target_include_directories(myQchart_lib
        PUBLIC
        ${CMAKE_BINARY_DIR}/myQchart)