#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

int main() {

  //   std::ios_base::sync_with_stdio(0);
  //   std::cin.tie(0);
  //   std::cout.tie(0);

  int64_t t;
  std::cin >> t;

  for (int64_t i = 0; i < t; ++i) {
    int64_t n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int64_t> a(n), d(m), f(k);

    for (int64_t j = 0; j < n; ++j) {
      std::cin >> a[j];
    }
    for (int64_t j = 0; j < m; ++j) {
      std::cin >> d[j];
    }
    for (int64_t j = 0; j < k; ++j) {
      std::cin >> f[j];
    }
    int64_t real_diff = 0;

    for (int64_t z = 1; z < n; ++z) {
      real_diff = std::max(real_diff, a[z] - a[z - 1]);
    }

    for (int64_t p = 0; p < m; ++p) {
      for (int64_t q = 0; q < k; ++q) {

        int64_t diff = 0;

        int64_t add = d[p] + f[q];

        for (int64_t z = 1; z < n; ++z) {
          diff = std::max(diff, a[z] - a[z - 1]);
        }

        for (int64_t z = 1; z < n; ++z) {
          if (a[z] > add && a[z - 1] <= add) {
            diff = std::max(diff, a[z] - add);
            diff = std::max(diff, add - a[z - 1]);
          }
        }

        if (a[n - 1] <= add) {
          diff = std::max(diff, add - a[n - 1]);
        }

        real_diff = std::min(real_diff, diff);
      }
    }
    std::cout << real_diff << '\n';
  }
}