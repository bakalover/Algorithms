#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
int main() {
  int64_t src, dest;
  std::cin >> src >> dest;
  std::vector<int64_t> d(10001000, -1);
  std::set<int64_t> q;

  d[src] = 0;

  q.insert(src);
  while (!q.empty()) {
    int64_t u = *q.begin();
    q.erase(q.begin());

    if (u == dest) {
      break;
    }

    int64_t mul = u * 2;
    int64_t minus = u - 1;

    if (d[mul] == -1) {
      d[mul] = d[u] + 1;
      q.insert(mul);
    }

    if ((minus > 0) && d[minus] == -1) {
      d[minus] = d[u] + 1;
      q.insert(minus);
    }
  }
  std::cout << d[dest];
}