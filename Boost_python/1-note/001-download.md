<link rel="stylesheet" type="text/css" href="auto-number-title.css" />

# 001_download: Boost 库安装与使用教程


本节将完整介绍 Boost 库的下载、安装（含无管理员权限的解决方案）及测试流程。


## 下载与解压 Boost 库
### 选择版本并下载
Boost 官方资源:   
- 最新版本: [Boost 官方网站](https://www.boost.org/)  
- 历史版本: [Boost 归档文件](https://archives.boost.io/release/)  

以 **1.88.0 版本** 为例，终端执行以下命令下载（任选一种格式）:   
```bash
# 方式 1: tar.gz 格式
wget https://archives.boost.io/release/1.88.0/source/boost_1_88_0.tar.gz

# 方式 2: tar.bz2 格式
wget https://archives.boost.io/release/1.88.0/source/boost_1_88_0.tar.bz2
```

### 解压文件
根据下载格式执行解压命令:   
```bash
# 解压 tar.gz 格式
tar -xzvf boost_1_88_0.tar.gz

# 解压 tar.bz2 格式
tar xf boost_1_88_0.tar.bz2  # 或 tar -xjvf boost_1_88_0.tar.bz2
```

进入解压后的目录:   
```bash
cd boost_1_88_0/
```


## 安装 Boost 库
### 准备编译环境（需管理员权限）
若有 `sudo` 权限，先安装依赖工具:   
```bash
# 检查 g++ 版本（确保已安装编译器）
g++ --version

# 更新包管理器并安装依赖
sudo apt update
sudo apt install build-essential python3 libbz2-dev libz-dev libicu-dev
```


### 编译与安装 Boost
在解压后的 `boost_1_88_0` 目录（或 Docker 容器内对应目录）执行:   
```bash
# 配置编译器和需安装的库（--with-libraries=all 表示安装所有库）
./bootstrap.sh --with-libraries=all --with-toolset=gcc

# 编译 Boost 库
./b2 toolset=gcc

# 安装（若有 sudo 权限，安装到系统目录）
sudo ./b2 install --prefix=/usr

# 更新动态链接库缓存
sudo ldconfig
```

### 卸载方法（如需）
```bash
sudo rm -rf /usr/local/include/boost
sudo rm -rf /usr/local/lib/libboost*
```


## 测试 Boost 库是否可用
以 `boost_thread` 模块为例，使用测试代码验证安装效果。

### 进入测试代码目录
测试代码存放路径为: [main_v1](../2-code/001-boost_thread/main_v1.cpp)、[main_v2](../2-code/001-boost_thread/main_v2.cpp)

```bash
# 替换为你自己的实际路径
cd /home/ic611/workspace/wr/LLM/boost/test_code/1-boost_thread
```

### 编译并运行测试程序
```bash
# 编译第一个测试程序（可能失败，用于对比）
g++ main_v1.cpp -g -o main -lboost_thread
./main  # 执行后可能失败（如权限或代码兼容问题）

# 编译第二个测试程序（优化后版本）
g++ main_v2.cpp -g -o main -lboost_thread
./main  # 执行后成功，说明 Boost 库正常工作
```


## 参考资料
- 官方指南: [Boost 安装文档](https://www.boost.org/doc/user-guide/getting-started.html)  
- 国内教程:   
  - [知乎: Boost 安装教程](https://zhuanlan.zhihu.com/p/539122040)  
  - [CSDN: Boost 编译与使用](https://blog.csdn.net/RadiantJeral/article/details/112757233)