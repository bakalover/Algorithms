#include <algorithm>
#include <cstddef>
#include <iostream>
int main() {
  int64_t A, B, C, D;
  std::cin >> A >> B >> C >> D;
  std::cout << A + std::max(D - B, (int64_t)0) * C;
}