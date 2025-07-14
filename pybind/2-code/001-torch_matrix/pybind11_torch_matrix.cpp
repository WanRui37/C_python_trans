#include <pybind11/embed.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <chrono>
#include <iostream>
#include <vector>

namespace py = pybind11;

void init_python() {
    static bool initialized = false;
    if (!initialized) {
        py::initialize_interpreter();
        initialized = true;
    }
}

py::array_t<double> matrix_multiply(const py::array_t<double>& a, const py::array_t<double>& b) {
    py::module_ torch = py::module_::import("torch");
    py::object result = torch.attr("matmul")(
        torch.attr("from_numpy")(a),
        torch.attr("from_numpy")(b)
    );
    return py::array_t<double>(py::cast<py::array>(result.attr("numpy")()));
}

py::array_t<double> matrix_add(const py::array_t<double>& a, const py::array_t<double>& b) {
    py::module_ torch = py::module_::import("torch");
    py::object result = torch.attr("from_numpy")(a) + torch.attr("from_numpy")(b);
    return py::array_t<double>(py::cast<py::array>(result.attr("numpy")()));
}

py::array_t<double> create_random_matrix(int rows, int cols) {
    py::module_ torch = py::module_::import("torch");
    return py::array_t<double>(py::cast<py::array>(torch.attr("rand")(rows, cols).attr("numpy")()));
}

// 计算吞吐率 (GFLOPS)
double calculate_throughput(double flops, double seconds) {
    return (flops / seconds) / 1e9; // GFLOPS = FLOPS/秒 / 1e9
}

int main() {
    init_python();
    
    // 矩阵维度
    const int M = 1024, N = 1024, K = 1024;
    
    // 创建随机矩阵
    auto a = create_random_matrix(M, K);
    auto b = create_random_matrix(K, N);
    
    // 预热
    matrix_multiply(a, b);
    
    // 测量乘法性能
    auto start = std::chrono::high_resolution_clock::now();
    auto result = matrix_multiply(a, b);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    
    // 计算理论浮点运算次数 (2*M*N*K)
    double flops = 2.0 * M * N * K;
    double throughput = calculate_throughput(flops, elapsed.count());
    
    std::cout << "Matrix Multiplication (" << M << "x" << N << "x" << K << "):" << std::endl;
    std::cout << "Time: " << elapsed.count() << " seconds" << std::endl;
    std::cout << "Throughput: " << throughput << " GFLOPS" << std::endl;
    
    // // 显式获取GIL后再释放解释器
    // py::gil_scoped_acquire acquire;
    // py::finalize_interpreter();
    
    return 0;
}