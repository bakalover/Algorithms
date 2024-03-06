#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
int main() {
  int64_t N, k = 1, p = 0;
  std::cin >> N;

  while (k < N) {
    p++;
    k *= 2;
  }

  std::cout << p;
}