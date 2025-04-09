cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 14)

# Source files
file(GLOB SOURCES
    "src/main.cpp"
    "src/Greeter.cpp"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add executable
add_executable(HelloWorld ${SOURCES})
