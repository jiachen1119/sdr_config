set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost COMPONENTS system REQUIRED)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)

find_package(Protobuf REQUIRED)
if(${Protobuf_VERSION} VERSION_LESS "3.0.0")
     message(FATAL_ERROR "Fatal error: Protocol Buffers >= v3.0.0 required.")
endif()

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/gnss_synchro.proto)


add_library(monitoring_lib ${CMAKE_CURRENT_SOURCE_DIR}/gnss_synchro_udp_source.cpp ${PROTO_SRCS})

target_link_libraries(monitoring_lib
    PUBLIC
        Boost::boost
        Boost::system
        ${CURSES_LIBRARIES}
        protobuf::libprotobuf
        pthread
)

target_include_directories(monitoring_lib
    PUBLIC
        ${CURSES_INCLUDE_DIRS}
        ${CMAKE_BINARY_DIR}/Monitor
)


