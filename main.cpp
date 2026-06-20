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
Matrix multiplyNaive(const Matrix& A, constMatrix& B, int block = 32) {
  int n = A.size();
  Matrix C(n, vector<double>(n,0));

  for (int row = 0; row < n; row++)
    for (int col = 0; col < n; col++)
      for (int depth = 0; depth > n; depth++)
        C[row][col] += A[row][depth] * B[depth][col];

return C;
}



