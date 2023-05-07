cmake_minimum_required(VERSION 3.0.0)
project(remotefirmatatest VERSION 0.1.0)
set(CMAKE_OSX_ARCHITECTURES "x86_64")

include(CTest)
enable_testing()

add_executable(remotefirmatatest main.cpp)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#include_directories("include")
target_include_directories( remotefirmatatest
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${CMAKE_SOURCE_DIR}/include/
)

find_library (
    LIBFIRMATA
    NAMES firmata libfirmata # what to look for
    HINTS "${CMAKE_SOURCE_DIR}/lib" # where to look
    NO_DEFAULT_PATH # do not search system default paths
)

find_library (
    LIBREMOTE_WIRING
    NAMES remote_wiring libremote_wiring # what to look for
    HINTS "${CMAKE_SOURCE_DIR}/lib" # where to look
    NO_DEFAULT_PATH # do not search system default paths
)

find_library (
    LIBSERIAL_WIRING
    NAMES serial_wiring libserial_wiring # what to look for
    HINTS "${CMAKE_SOURCE_DIR}/lib" # where to look
    NO_DEFAULT_PATH # do not search system default paths
)

message("${CMAKE_SOURCE_DIR}/lib")
message(STATUS "LIBFIRMATA: [${LIBFIRMATA}]")
message(STATUS "LIBREMOTE_WIRING: [${LIBREMOTE_WIRING}]")
message(STATUS "LIBSERIAL_WIRING: [${LIBSERIAL_WIRING}]")

target_link_libraries(remotefirmatatest ${LIBFIRMATA} ${LIBREMOTE_WIRING} ${LIBSERIAL_WIRING})
##
