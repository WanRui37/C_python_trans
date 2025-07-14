#include <torch/torch.h>
#include <iostream>

int main() {
  // 生成随机整数矩阵（0-9）
  torch::Tensor tensor_in_1 = torch::randint(10, {2, 3}); // 2x3 矩阵
  torch::Tensor tensor_in_2 = torch::randint(10, {3, 4}); // 3x4 矩阵
  
  // 使用 matmul 进行矩阵乘法（正确方式）
  torch::Tensor tensor_out = torch::matmul(tensor_in_1, tensor_in_2);
  
  // 打印结果
  std::cout << "Input 1:" << std::endl << tensor_in_1 << std::endl;
  std::cout << "Input 2:" << std::endl << tensor_in_2 << std::endl;
  std::cout << "Output (Matrix Multiplication):" << std::endl << tensor_out << std::endl;
  
  // 验证输出形状（应为 2x4）
  std::cout << "Output shape: " << tensor_out.sizes() << std::endl;
}