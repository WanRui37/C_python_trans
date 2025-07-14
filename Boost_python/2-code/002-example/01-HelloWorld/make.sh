#!/bin/bash

# 确保当前目录下没有 build 目录（可选）
if [ -d "build" ]; then
    echo "清除现有 build 目录..."
    rm -rf build
fi

# 创建并进入 build 目录
mkdir -p build && cd build || exit 1  # 如果创建/进入失败则退出

# 运行 CMake 配置
echo "运行 CMake 配置..."
cmake .. || exit 1  # 如果 CMake 失败则退出

# 编译项目
echo "开始编译..."
make -j "$(nproc)" || exit 1  # 使用所有 CPU 核心编译，失败则退出

echo "编译完成！"