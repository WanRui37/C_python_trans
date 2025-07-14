<link rel="stylesheet" type="text/css" href="auto-number-title.css" />

# 002-example: Boost 各种案例

本节将完整介绍 Boost 各种案例，其源码是[TNG/boost-python-examples](https://github.com/TNG/boost-python-examples)

但是源码是没办法直接跑通的，`./build.sh`一直失败。
## 软件包安装

如果环境有问题重新 apt install 安装

```bash
sudo apt remove libboost-all-dev
sudo rm -rf /usr/local/include/boost
sudo rm -rf /usr/local/lib/libboost*
sudo rm -rf /usr/include/boost
sudo rm -rf /usr/lib/libboost*
sudo rm -rf /usr/lib/cmake/boost_python*

sudo apt install libboost-all-dev
```

我也提供了 dockerfile 文件

```bash
cd /home/ic611/workspace/wr/LLM/boost/env

sudo docker build -t boost:latest -f ./boost_20_04.dockerfile .

sudo docker run -it -v $(pwd):$(pwd) -w $(pwd) --network host boost
```

## 单个例子编译运行
g++编译运行
```bash
cd path/to/your_project

bash ./build.sh
python xxx.py
```

cmake编译运行
```bash
cd path/to/your_project

bash ./make.sh
python ./build/xxx.py
```


## 多个例子编译运行
```bash
python ./build.py
```

## 例子讲解
这些示例展示了如何使用 `Boost.Python` 库将 C++ 代码集成到 Python 环境中，下面是各个示例的作用：

### 01-HelloWorld
- **作用**：这是一个基础的示例，展示了如何使用 `Boost.Python` 将一个简单的 C++ 函数暴露给 Python。在 C++ 中定义了一个返回字符串 `"hello, world"` 的函数，然后通过 `Boost.Python` 将其封装成 Python 模块，最后在 Python 代码中导入该模块并调用该函数。

### 02-ExposingClasses
- **作用**：演示了如何将 C++ 类暴露给 Python。定义了一个 `World` 结构体，包含设置消息、处理多个消息和获取消息的方法。通过 `Boost.Python` 将该结构体封装成 Python 模块，Python 代码可以创建该类的实例并调用其方法。

### 03-Constructors
- **作用**：展示了如何在 C++ 类中定义不同的构造函数，并将其暴露给 Python。定义了一个 `Ctor` 结构体，包含接受字符串和两个双精度浮点数的构造函数，Python 代码可以使用这些构造函数创建对象。

### 04-ClassMembers
- **作用**：说明如何将 C++ 类的成员变量和成员函数暴露给 Python。定义了一个 `SomeClass` 类，包含一个公共成员变量 `name` 和私有成员变量 `mNumber`，以及对应的获取和设置方法。Python 代码可以直接访问和修改这些成员。

### 05-Inheritance
- **作用**：展示了如何处理 C++ 类的继承关系，并将其暴露给 Python。定义了 `Base` 和 `Derived` 类，`Derived` 类继承自 `Base` 类。通过 `Boost.Python` 将这些类封装成 Python 模块，Python 代码可以使用这些类及其继承关系。

### 06-VirtualFunctionsInPython
- **作用**：演示了如何在 Python 中重写 C++ 类的虚函数。定义了一个 `Base` 类，包含一个虚函数 `name`。在 Python 中创建 `Base` 类的派生类 `PythonDerived`，并重写 `name` 函数。Python 代码可以调用这些函数。

### 07-Operators
- **作用**：展示了如何在 C++ 类中重载运算符，并将其暴露给 Python。定义了一个 `NumberLike` 类，重载了 `+=` 和 `+` 运算符。Python 代码可以像使用 Python 内置类型一样使用这些运算符。

### 08-CallPolicies
- **作用**：说明如何使用 `Boost.Python` 的调用策略。定义了一个 `Example` 类，包含工厂方法和单例方法。通过不同的调用策略将这些方法暴露给 Python，Python 代码可以使用这些方法创建对象。

### 09-Overloading
- **作用**：展示了如何在 C++ 类中实现函数重载，并将其暴露给 Python。定义了一个 `Example` 类，包含多个重载的 `doit` 方法和一个带有默认参数的 `makeIt` 方法。Python 代码可以根据不同的参数调用这些重载函数。

### 10-Embedding
- **作用**：演示了如何在 C++ 代码中嵌入 Python 解释器，并执行 Python 脚本。在 C++ 代码中初始化 Python 解释器，导入 Python 模块，创建 C++ 对象并将其传递给 Python 脚本，然后执行 Python 脚本。

### 11-Iterators
- **作用**：展示了如何将 C++ 类的迭代器暴露给 Python。定义了一个 `Example` 类，包含一个 `std::vector<std::string>` 成员变量和对应的迭代器方法。通过 `Boost.Python` 将这些迭代器方法封装成 Python 模块，Python 代码可以像使用 Python 迭代器一样遍历该类的元素。

### 12-Exceptions
- **作用**：说明如何在 C++ 代码中抛出异常，并将其映射到 Python 异常。定义了一个 `myexceptions` 模块，注册了异常转换器，将 C++ 异常转换为 Python 异常。Python 代码可以捕获这些异常。

### 13-AutoInstantiation
- **作用**：演示了如何在 C++ 代码中自动实例化 Python 类的子类。在 C++ 代码中初始化 Python 解释器，导入 Python 模块，执行 Python 脚本，然后遍历 Python 命名空间，自动实例化所有继承自 `Base` 类的子类，并调用其方法。