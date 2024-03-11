#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <set>
#include <string>
#include <vector>

int main() {

  //   std::ios_base::sync_with_stdio(0);
  //   std::cin.tie(0);
  //   std::cout.tie(0);

  std::int64_t t;
  std::cin >> t;

  for (int64_t i = 0; i < t; ++i) {
    int64_t n, m, x, r;
    char c;
    std::cin >> n >> m >> x;

    std::set<int64_t> potential_players;
    potential_players.insert(x);

    for (int64_t j = 0; j < m; ++j) {


      std::cin >> r >> c;

      std::vector<int64_t> pls;
      for (auto it = potential_players.begin(); it != potential_players.end();
           ++it) {
        pls.push_back(*it);
      }
      potential_players.clear();

      for (auto pl : pls) {

        if (c == '0') {
          int64_t m = pl + r;
          if (m > n) {
            m %= n;
          }
          potential_players.insert(m);
        }
        if (c == '1') {
          int64_t mm = pl - r;
          if (mm == 0) {
            mm = n;
          } else if (mm < 0) {
            mm = n + mm;
          }
          potential_players.insert(mm);
        }
        if (c == '?') {
          int64_t m = pl + r;
          if (m > n) {
            m %= n;
          }
          potential_players.insert(m);

          int64_t mm = pl - r;
          if (mm == 0) {
            mm = n;
          } else if (mm < 0) {
            mm = n + mm;
          }
          potential_players.insert(mm);
        }
      }
    }
    std::cout << potential_players.size() << '\n';
    for (auto it = potential_players.begin(); it != potential_players.end();
         ++it) {
      std::cout << *it << ' ';
    }
    std::cout << std::endl;
  }
}