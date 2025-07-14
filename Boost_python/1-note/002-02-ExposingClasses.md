<link rel="stylesheet" type="text/css" href="auto-number-title.css" />

# 02-ExposingClasses

`02-ExposingClasses` 示例展示了如何使用 `Boost.Python` 库将 C++ 类暴露给 Python 环境。以下是对 `classes.cpp` 和 `classes.py` 文件的详细技术要点讲解。

## C++ 代码 (`classes.cpp`)

### 技术要点
1. **头文件引入**：
    - `#include <boost/python.hpp>`：引入 `Boost.Python` 库的核心头文件。
    - `#include <boost/python/list.hpp>`：引入处理 Python 列表的头文件。
    - `#include <boost/python/extract.hpp>`：引入从 Python 对象中提取 C++ 类型的头文件。

2. **`World` 结构体**：
    - `set` 方法：用于设置 `mMsg` 成员变量的值。
    - `many` 方法：接受一个 Python 列表，将列表中的字符串拼接成一个字符串，并设置给 `mMsg`。
    - `greet` 方法：返回 `mMsg` 的值。

3. **`BOOST_PYTHON_MODULE` 宏**：
    - 用于定义一个 Python 模块，模块名为 `classes`。
    - `class_<World>("World")`：将 `World` 结构体暴露给 Python，Python 中对应的类名也为 `World`。
    - `.def` 方法：用于将 C++ 类的成员函数暴露给 Python，使其可以在 Python 中调用。

## Python 代码 (`classes.py`)

### 技术要点
1. **模块导入**：
    - `import classes`：导入之前在 C++ 代码中定义的 `classes` 模块。

2. **类实例化和方法调用**：
    - `t = classes.World()`：创建 `World` 类的实例。
    - `t.set("bom dia!")`：调用 `World` 类的 `set` 方法设置消息。
    - `t.greet()`：调用 `World` 类的 `greet` 方法获取消息并打印。
    - `t.many(['Good Morning', 'Buon giorno', 'Kali mera'])`：调用 `World` 类的 `many` 方法处理多个消息。

## 总结
`02-ExposingClasses` 示例通过 `Boost.Python` 库将 C++ 类暴露给 Python 环境。主要步骤包括：在 C++ 代码中定义类并使用 `Boost.Python` 宏将其封装成 Python 模块，在 Python 代码中导入并实例化该模块中的类，然后调用类的成员方法。这种方式使得 C++ 类可以无缝地集成到 Python 项目中。