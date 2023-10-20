cmake_minimum_required(VERSION 3.26)
project(k_mean)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Widgets
        Core
        REQUIRED)

add_executable(k_mean main.cpp
        KMean.cpp
        KMean.h
        Centroid.cpp
        Centroid.h
        Position.cpp
        Position.h
        Widget.cpp
        Widget.h)
target_link_libraries(k_mean
        Qt5::Core
        Qt5::Widgets
)

