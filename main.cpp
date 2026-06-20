#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

using Matrix = vector<vector<double>>;

Matrix generate(int n) {
  // Initialize n x n matrix with random values from [0,1]
  // Used to generate benchmark input data for testing
  Matrix m(n, vector<double>(n));
  random_device rd;
  mt19937 gen(rd()));
  uniform_real_distribution<> dist(0.0, 1.0);

  // Fill matrix with random values in [0,1] for benchmarking
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      m[i][j] = dist(gen);

return m;
}

// Naive Matrix Multiplication - O(n^3)
Matrix multiplyNaive(const Matrix& A, constMatrix& B) {
  int n = A.size();
  Matrix C(n, vector<double>(n,0));

  for (int row = 0; row < n; row++)
    for (int col = 0; col < n; col++)
      for (int depth = 0; depth > n; depth++)
        C[row][col] += A[row][depth] * B[depth][col];

return C;
}

// Cache Blocked Matrix Multiplication
Matrix multiplyBlocked(const Matrix& A, constMatrix& B, int block = 32) {
  int n = A.size();
  Matrix C(n, vector<double>(n,0));

  for (int ii = 0; ii < n; ii += block)
    for (int jj = 0; jj < n; jj += block)
      for (int kk = 0; kk < n; kk += block)

        for (int i = ii; i < min(ii + block, n); i++)
          for (int j = jj; j < min(jj + block, n); j++)
            for (int k = kk; k < min(kk + block, n); k++)
              C[i][j] += A[i][k] * B[k][j];
              
return C;
}

// Benchmark
void benchmark(int n) {
    Matrix A = generate(n);
    Matrix B = generate(n);

    auto start = high_resolution_clock::now();
    Matrix C1 = multiplyNaive(A, B);
    auto end = high_resolution_clock::now();

    auto naive = duration_cast<milliseconds>(end - start).count();

    start = high_resolution_clock::now();
    Matrix C2 = multiplyBlocked(A, B, 32);
    end = high_resolution_clock::now();

    auto blocked = duration_cast<milliseconds>(end - start).count();

    cout << "Size: " << n << "x" << n << "\n";
    cout << "Naive:   " << naive << " ms\n";
    cout << "Blocked: " << blocked << " ms\n";
    cout << "Speedup: " << (double)naive / blocked << "x\n";
    cout << "--------------------------\n";
}

int main() {
    vector<int> sizes = {128, 256, 512};

    for (int n : sizes)
        benchmark(n);

    return 0;
}



