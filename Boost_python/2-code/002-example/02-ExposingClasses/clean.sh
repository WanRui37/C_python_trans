#!/bin/bash

# 确保当前目录下没有 build 目录（可选）
if [ -d "build" ]; then
    echo "清除现有 build 目录..."
    rm -rf build
fi

rm *.so