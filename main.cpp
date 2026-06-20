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


