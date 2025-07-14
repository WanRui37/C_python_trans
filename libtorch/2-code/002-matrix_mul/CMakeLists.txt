cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(matrix_mul)
 
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
 
add_executable(matrix_mul matrix_mul.cpp)
target_link_libraries(matrix_mul "${TORCH_LIBRARIES}")
set_property(TARGET matrix_mul PROPERTY CXX_STANDARD 14)