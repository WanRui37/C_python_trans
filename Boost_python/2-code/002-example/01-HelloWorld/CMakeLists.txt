# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

# 查找Python和Boost
# set(Python3_ROOT_DIR "/usr/include/python3.8")
# find_package(PythonLibs 3 REQUIRED)
# find_package(Boost)

find_package(Python3 COMPONENTS Development REQUIRED)
find_package(Boost COMPONENTS python38)

# 添加共享库目标
add_library(hello SHARED hello.cpp)

# 链接库
target_include_directories(hello PRIVATE
    ${Python3_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)
target_link_libraries(hello PRIVATE
    ${Python3_LIBRARIES}
    ${Boost_LIBRARIES}
)
message(STATUS "Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3_LIBRARIES: ${Python3_LIBRARIES}")
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")

# 设置输出名称和属性
set_target_properties(hello PROPERTIES 
    PREFIX ""                  # 移除默认的lib前缀
    SUFFIX ".so"               # 设置后缀为.so
)

add_custom_target(copy_python_files
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/hello.py ${CMAKE_BINARY_DIR}
    COMMENT "复制Python脚本到build目录"
)

add_dependencies(hello copy_python_files)