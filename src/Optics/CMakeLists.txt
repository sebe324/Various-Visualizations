cmake_minimum_required(VERSION 3.5)

file(GLOB OPTICS_SRC
     "*.h"
     "*.cpp"
)

add_library(optics ${OPTICS_SRC})

add_dependencies(optics utilities)

target_include_directories(optics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(optics PRIVATE Qt${QT_VERSION_MAJOR}::Widgets utilities)

