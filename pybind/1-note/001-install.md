# pybind11安装与测试指南

## 安装

首先进入工作目录并启动docker环境：
```bash
cd /home/ic611/workspace/wr/LLM/boost/env
sudo docker run -it -v $(pwd):$(pwd) -w $(pwd) --network host boost-clang11
```

在docker容器内安装必要的Python工具：
```bash
# 注意：不能使用apt-get install python-setuptools，它安装的是python2.7的
apt-get install python3-setuptools
apt install python3-pip
pip install pybind11
```

安装成功后会显示以下提示：
```
Successfully installed pybind11-3.0.0
```

获取示例工程：
```bash
cd /home/ic611/workspace/wr/LLM/boost/env/pybind
```

在非docker环境的终端中执行以下命令克隆工程：
```bash
# 使用SSH方式
git clone git@two.github.com:pybind/python_example.git
# 或者使用HTTPS方式
git clone https://github.com/pybind/python_example.git
```

回到docker终端，进入工程目录并安装：
```bash
cd /home/ic611/workspace/wr/LLM/boost/env/pybind/
# 下面一级就是python_example
pip install ./python_example
```

安装过程说明：
1. pip会尝试在这个文件夹里寻找包的元数据文件（像setup.py或者pyproject.toml），然后依据这些文件来安装包。

安装成功后会显示：
```
Successfully built python-example
Installing collected packages: python-example
Successfully installed python-example-0.0.1
```

如果需要卸载，可以使用下面的命令：
```bash
pip uninstall python-example
```

## 测试

执行以下命令进行测试：
```bash
cd /home/ic611/workspace/wr/LLM/boost/env/pybind/python_example/tests
python ./test.py
```


## conda
或者是使用conda环境
```bash
conda activate torch-1.13
conda install conda-forge::pybind11
pip install ./python_example

cd /home/ic611/workspace/wr/LLM/boost/env/pybind/python_example/tests

python ./test.py

pip uninstall python-example
```