cmake_minimum_required(VERSION 3.5)

file(GLOB COLLISIONS_SRC
     "*.h"
     "*.cpp"
)

add_library(collisions ${COLLISIONS_SRC})

add_dependencies(collisions utilities)

target_include_directories(collisions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(collisions PRIVATE Qt${QT_VERSION_MAJOR}::Widgets utilities)

