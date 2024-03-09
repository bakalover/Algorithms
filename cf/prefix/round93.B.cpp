#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <string>
int main() {
  std::string s;

  std::cin >> s;

  int p[s.length()];
  p[0] = 0;

  for (std::int64_t i = 1; i <= s.length() - 1; ++i) {
    int k = p[i - 1];
    while (k > 0 && s[i] != s[k]) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      ++k;
    }
    p[i] = k;
  }

  if (p[s.length() - 1] != 0) {
    for (std::int64_t i = 0; i < s.length() - 1; ++i) {
      if (p[i] == p[s.length() - 1]) {
        std::cout << s.substr(0, p[s.length() - 1]);
        return 0;
      }
    }
  } else {
    std::cout << "Just a legend";
    return 0;
  }
  if (p[p[s.length() - 1] - 1] != 0) {
    std::cout << s.substr(0, p[p[s.length() - 1] - 1]);
    return 0;
  }
  std::cout << "Just a legend";
  return 0;
}