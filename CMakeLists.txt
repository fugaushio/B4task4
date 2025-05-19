cmake_minimum_required(VERSION 3.10)
project(PoissonSolver)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 REQUIRED)

include_directories(include)

file(GLOB SOURCES
    "src/*.cpp"
)

add_executable(PoissonSolver ${SOURCES})
target_link_libraries(PoissonSolver Eigen3::Eigen)