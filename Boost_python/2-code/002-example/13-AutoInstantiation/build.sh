#!/bin/bash

# 编译共享库 mymodule
g++ -o auto_instance \
    myextension.cpp auto_instance.cpp \
    -I /usr/include/python3.8 \
    -lboost_python38 -lpython3.8

# 运行测试
./auto_instance