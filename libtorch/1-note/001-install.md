#  LibTorch

LibTorch 是 PyTorch 的 C++ 发行版，PyTorch 是一种流行的开源机器学习框架。通过 LibTorch，开发者可以在 C++ 环境中直接使用 PyTorch 的张量操作、模型推理等核心功能，无需依赖 Python 解释器。


##  安装

### 安装方式选择
LibTorch 支持源码构建和预编译包安装两种方式。由于源码构建依赖较多且体积庞大，推荐使用预编译包进行安装。


### 步骤1：下载预编译包
PyTorch 官网提供了所有版本的 LibTorch 预编译包，CPU 版本的下载地址为：  
[https://download.pytorch.org/libtorch/cpu](https://download.pytorch.org/libtorch/cpu)

以 **1.13.0 版本（CPU，C++11 ABI，带依赖）** 为例，使用 `wget` 命令下载：
```bash
$ wget https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-1.13.0%2Bcpu.zip
```


### 步骤2：解压安装包
使用 `unzip` 命令解压下载的 zip 包：
```bash
$ unzip libtorch-cxx11-abi-shared-with-deps-1.13.0+cpu.zip
```

解压后会生成 `libtorch` 目录，包含头文件、库文件等内容。


### 步骤3：在 CMake 中配置 LibTorch
在编译依赖 LibTorch 的项目时，需通过 `CMAKE_PREFIX_PATH` 指定 LibTorch 的路径。假设解压后的 `libtorch` 目录位于：  
`/home/ic611/workspace/wr/LLM/boost/env/libtorch/libtorch`

则 CMake 配置命令为：
```bash
$ cmake -DCMAKE_PREFIX_PATH=/home/ic611/workspace/wr/LLM/boost/env/libtorch/libtorch ..
```


### 步骤4：编译项目
配置完成后，使用 `make` 命令编译项目：
```bash
$ mkdir build

$ cd build

$ cmake -DCMAKE_PREFIX_PATH=/path/to/libtorch ..

$ make
```

（可选）添加 `-j$(nproc)` 选项利用多核心加速编译：
```bash
$ make -j$(nproc)
```


### 参考文档
- [CSDN 文档：LibTorch 安装与使用](https://blog.csdn.net/LconLu/article/details/128171775)
- [GitHub 官方文档：LibTorch 入门](https://github.com/pytorch/pytorch/blob/main/docs/libtorch.rst)