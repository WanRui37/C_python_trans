#!/bin/bash

# 创建 build 目录（如果不存在）
mkdir -p build

# 进入 build 目录
cd build || {
    echo "错误：无法进入 build 目录，请检查权限或目录是否存在"
    exit 1
}

# 执行 cmake 配置（指定 LibTorch 路径）
cmake -DCMAKE_PREFIX_PATH=/home/ic611/workspace/wr/LLM/boost/env/libtorch/libtorch .. || {
    echo "错误：cmake 配置失败"
    exit 1
}

# 执行编译（默认使用所有可用 CPU 核心加速编译）
make -j$(nproc) || {
    echo "错误：make 编译失败"
    exit 1
}

echo "编译完成！可执行文件位于 build 目录中"