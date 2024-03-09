#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
  int64_t N, arr_i, tickets = 0, ans = 0;
  std::cin >> N;
  std::vector<int64_t> buff;
  for (int64_t i = 0; i < N; ++i) {
    std::cin >> arr_i;
    if (arr_i > 100) {
      ++tickets;
    }
  }
}