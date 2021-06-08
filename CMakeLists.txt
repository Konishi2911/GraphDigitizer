# Required CMake Version
cmake_minimum_required(VERSION 3.16)

# Define Project
project(ChartReader)

# set Qt Directory
set(Qt6_DIR /opt/homebrew/bin)
list(APPEND CMAKE_PREFIX_PATH ${Qt6_DIR})

# use of MOC, RCC, UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Search Qt Package
find_package(Qt6 COMPONENTS Core Widgets Quick REQUIRED)



# Add subdirectories
add_subdirectory(src)
