#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>
int main() {
  int64_t N, a_i;
  std::vector<int64_t> odd, even, all;

  std::cin >> N;
  for (int64_t i = 1; i <= N; ++i) {
    std::cin >> a_i;
    all.push_back(i);
    if (a_i % 2 == 1 && i % 2 == 0) {
      odd.push_back(i);
    }
    if (a_i % 2 == 0 && i % 2 == 1) {
      even.push_back(i);
    }
  }

  // Check that EXACTLY ONE of even and ONE of odd are wrong
  if (odd.size() + even.size() == 2 && !odd.empty() && !even.empty()) {
    std::cout << odd.back() << " " << even.back();
  } else if (odd.empty() && even.empty()) {
    if (N % 2 == 1) {
      std::cout << all[0] << " " << all[2];
    } else if (N >= 4) {
      std::cout << all[1] << " " << all[3];
    } else {
      std::cout << -1 << " " << -1;
    }
  } else {
    std::cout << -1 << " " << -1;
  }
}