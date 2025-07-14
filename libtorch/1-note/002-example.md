# Example

## 编译+运行
以下是编译项目的脚本 `build.sh`，用于自动化构建过程：

```bash
$ bash ./build.sh

$ ./build/gen_matrix

$ ./build/matrix_mul
```

## 扩展学习
LibTorch 还支持神经网络构建、自动微分、模型加载等高级功能，更多用法可参考：
- [LibTorch 官方文档](https://docs.pytorch.org/cppdocs/frontend.html)（C++ 前端完整指南）
- [PyTorch C++ API 参考](https://pytorch.org/cppdocs/api/library_root.html)（详细 API 说明）
- [LibTorch tensor API 参考](https://docs.pytorch.org/cppdocs/api/classat_1_1_tensor.html#exhale-class-classat-1-1-tensor)