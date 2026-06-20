# Cache-Aware-Matrix-Multiplication
This project compares **naive** and **cache-blocked** implementations of matrix multiplication in C++ to analyze how memory access patterns and cache locality affect performance.

## What it does
- Implements **naive matrix multiplication**
- Implements **blocked (tiled) matrix multiplication** for improved cache efficiency
- Benchmarks both implementations using `std::chrono`
- Compares runtime across multiple matrix sizes (128, 256, 512)

## Key idea
**Blocking improves performance by increasing cache reuse and reducing memory access latency**, which is often the main bottleneck in dense linear algebra operations.

## Results
Blocked matrix multiplication consistently performs faster than the naive version, with increasing benefits as matrix size grows.



