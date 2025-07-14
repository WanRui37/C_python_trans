cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(gen_matrix)
 
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")
 
add_executable(gen_matrix gen_matrix.cpp)
target_link_libraries(gen_matrix "${TORCH_LIBRARIES}")
set_property(TARGET gen_matrix PROPERTY CXX_STANDARD 14)