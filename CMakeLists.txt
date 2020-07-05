cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
    src/main.cpp
    src/drawing/drawing.cpp
    src/drawing/drawing.h
    src/utils/random/random.cpp
    src/utils/random/random.h
    src/drawing/components/button.cpp
    src/drawing/components/button.h
    src/utils/vector_i.h
    src/utils/pointer/pointer.cpp
    src/utils/pointer/pointer.h
    src/showcase/showcase.cpp
    src/showcase/showcase.h
    src/algorithms/bubble_sort.cpp
    src/algorithms/bubble_sort.h
    src/utils/thread/thread.cpp
    src/utils/thread/thread.h
    src/algorithms/quick_sort.cpp
    src/algorithms/quick_sort.h
    src/algorithms/shaker_sort.cpp
    src/algorithms/shaker_sort.h
    src/algorithms/insertion_sort.cpp
    src/algorithms/insertion_sort.h
    src/algorithms/merge_sort.cpp
    src/algorithms/merge_sort.h
)

project(AlgorithmsVisualisation)

# Raylib settings
# Sets support for high-dpi monitors, change if building for different platforms (no-desktop)
set(PLATFORM_DESKTOP ON)
set(SUPPORT_HIGH_DPI ON)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
find_package(raylib 3.0 QUIET)
add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)
