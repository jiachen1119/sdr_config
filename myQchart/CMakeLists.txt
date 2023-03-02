find_package(Qt5Charts)
find_package(Qt5PrintSupport REQUIRED)
add_library(myQchart_lib myQchart.cpp qcustomplot.cpp)
target_link_libraries(myQchart_lib
        PUBLIC
        Qt5::Charts
        Qt5::PrintSupport
        Qt5::Widgets)