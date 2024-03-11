#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

int main() {

  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::int64_t t;
  std::cin >> t;
  for (int64_t i = 0; i < t; ++i) {
    int64_t n, m, k, c = 0;
    std::cin >> n >> m >> k;
    std::vector<int64_t> arr1(n), arr2(m);
    for (int64_t j = 0; j < n; ++j) {
      std::cin >> arr1[j];
    }
    for (int64_t j = 0; j < m; ++j) {
      std::cin >> arr2[j];
    }

    for (int64_t j = 0; j < n; ++j) {
      for (int64_t p = 0; p < m; ++p) {
        if (arr1[j] + arr2[p] <= k) {
          ++c;
        }
      }
    }
    std::cout << c << '\n';
  }
}