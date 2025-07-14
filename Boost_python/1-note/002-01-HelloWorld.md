<link rel="stylesheet" type="text/css" href="auto-number-title.css" />

# 01-HelloWorld

`01-HelloWorld` 示例展示了如何使用 `Boost.Python` 库将 C++ 函数暴露给 Python 环境。下面将详细讲解其技术要点：

## C++ 代码 (`hello.cpp`)
### 技术要点
- **`greet` 函数**：这是一个简单的 C++ 函数，返回一个字符串 `"hello, world"`。
- **`#include <boost/python.hpp>`**：引入 `Boost.Python` 库的头文件，该库提供了将 C++ 代码与 Python 交互的功能。
- **`BOOST_PYTHON_MODULE(hello)`**：这是 `Boost.Python` 提供的宏，用于定义一个 Python 模块。`hello` 是模块的名称，Python 代码可以通过这个名称导入该模块。
- **`def("greet", greet)`**：`def` 是 `Boost.Python` 命名空间中的函数，用于将 C++ 函数 `greet` 暴露给 Python。在 Python 中，可以通过模块名和函数名来调用这个 C++ 函数。

## Python 代码 (`hello.py`)
### 技术要点
- **`import hello`**：导入之前在 C++ 代码中定义的 `hello` 模块。
- **`print (hello.greet())`**：调用 `hello` 模块中的 `greet` 函数，并打印其返回值。