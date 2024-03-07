#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iostream>

// Fast pow + finite field
int FastCircularPow(int64_t n, int64_t pow, int64_t p) {
  int64_t res = 1;
  while (pow > 0) {
    if (pow % 2 == 1) {
      res = (res * n) % p;
    }
    n = (n * n) % p;
    pow /= 2;
  }
  return res % p;
}

int main() {
  int64_t l, r, p, res = 0;
  std::cin >> l >> r >> p;
  for (int64_t i = l; i <= r; ++i) {
    // finite field
    res = (res + FastCircularPow(i, p - 2, p)) % p;
  }
  std::cout << res;
}