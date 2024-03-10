#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
int main() {
double x_i, y_i, all = 0, n;
  std::cin >> n;
  for (int64_t i = 0; i < n; ++i) {
    std::cin >> x_i >> y_i;
    all += x_i;
  }

  std::cout << all / n;
}