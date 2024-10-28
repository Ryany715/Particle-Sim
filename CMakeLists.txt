cmake_minimum_required(VERSION 3.5.0)
project(Particle-Sim VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/blitz/include)
find_library(BLITZ_LIB blitz HINTS ${CMAKE_CURRENT_SOURCE_DIR}/libs/blitz/include)
add_executable(Particle-Sim main.cpp)
target_link_libraries(Particle-Sim PUBLIC ${BLITZ_LIB})



