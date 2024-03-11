#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/types.h>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::int64_t t;
  std::string s;
  std::cin >> t;
  for (int64_t i = 0; i < t; ++i) {
    int64_t c = 0, n;
    std::cin >> n >> s;
    for (int64_t j = 1; j <= n - 2; ++j) {

      if (s[j - 1] == 'm' && s[j] == 'a' && s[j + 1] == 'p') {
        c++;
      }
      if (s[j - 1] == 'p' && s[j] == 'i' && s[j + 1] == 'e') {
        if (j >= 3 && s[j - 2] == 'a' && s[j - 3] == 'm') {
          continue;
        }
        c++;
        continue;
      }
    }
    std::cout << c << std::endl;
  }
}