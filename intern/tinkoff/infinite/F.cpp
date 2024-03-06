#include <algorithm>
#include <cstddef>
#include <iostream>
int main() {
  int64_t N, a_i, odd = -1, even = -1, c = 0;
  std::cin >> N;
  for (std::size_t i = 1; i <= N; ++i) {
    std::cin >> a_i;
    if (a_i % 2 == 1 && i % 2 == 0) {
      odd = i;
      ++c;
    }
    if (a_i % 2 == 0 && i % 2 == 1) {
      even = i;
      ++c;
    }
  }

  // Check that EXACTLY ONE of even and ONE of odd are wrong
  if (c == 2 && odd != -1 && even != -1) {
    std::cout << odd << " " << even;
  } else {
    std::cout << -1 << " " << -1;
  }
}