#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <stdint.h>
#include <vector>
using namespace std;

struct OrderInfo {
  int64_t start, end, diff, cost;
};

struct CostInfo {
  int64_t ll, rl, cost;
};

struct TimeInfo {
  int64_t lr, rr, time;
};

struct Tree {
  vector<CostInfo> datacost;
  vector<TimeInfo> datatime;
  int64_t size;

  void Init(int64_t n) {
    size = 1;
    while (size < n) {
      size *= 2;
    }
    datacost.assign(2 * size, CostInfo{INT64_MAX, INT64_MIN, 0});
    datatime.assign(2 * size, TimeInfo{INT64_MAX, INT64_MIN, 0});
  }

  void Construct(vector<OrderInfo> &arr) {
    Init(arr.size());
    std::sort(arr.begin(), arr.end(),
              [](OrderInfo &x, OrderInfo &y) { return x.start < y.start; });

    ConstructCost(arr, 0, 0, this->size);

    std::sort(arr.begin(), arr.end(),
              [](OrderInfo &x, OrderInfo &y) { return x.end < y.end; });

    ConstructTime(arr, 0, 0, this->size);
  }

  void ConstructCost(vector<OrderInfo> &orders, int64_t x, int64_t l,
                     int64_t r) {
    if (l >= orders.size()) {
      return;
    }

    if (r - l == 1) {
      datacost[x].ll = orders[l].start;
      datacost[x].rl = orders[l].start;
      datacost[x].cost = orders[l].cost;
      return;
    }

    int64_t m = (l + r) / 2;

    ConstructCost(orders, 2 * x + 1, l, m);
    ConstructCost(orders, 2 * x + 2, m, r);

    datacost[x].cost = datacost[2 * x + 1].cost + datacost[2 * x + 2].cost;
    datacost[x].ll = min(datacost[2 * x + 1].ll, datacost[2 * x + 2].ll);
    datacost[x].rl = max(datacost[2 * x + 1].rl, datacost[2 * x + 2].rl);
  }

  void ConstructTime(vector<OrderInfo> &orders, int64_t x, int64_t l,
                     int64_t r) {
    if (l >= orders.size()) {
      return;
    }
    if (r - l == 1) {
      datatime[x].lr = orders[l].end;
      datatime[x].rr = orders[l].end;
      datatime[x].time = orders[l].diff;
      return;
    }

    int64_t m = (l + r) / 2;

    ConstructTime(orders, 2 * x + 1, l, m);
    ConstructTime(orders, 2 * x + 2, m, r);

    datatime[x].time = datatime[2 * x + 1].time + datatime[2 * x + 2].time;
    datatime[x].lr = min(datatime[2 * x + 1].lr, datatime[2 * x + 2].lr);
    datatime[x].rr = max(datatime[2 * x + 1].rr, datatime[2 * x + 2].rr);
  }

  int64_t FindCost(int64_t l, int64_t r) { return FindCost(l, r, 0); }

  int64_t FindCost(int64_t l, int64_t r, int64_t x) {
    if (l > datacost[x].rl || r < datacost[x].ll) {
      return 0;
    }
    if (l <= datacost[x].ll && r >= datacost[x].rl) {
      return datacost[x].cost;
    }
    return FindCost(l, r, 2 * x + 1) + FindCost(l, r, 2 * x + 2);
  }

  int64_t FindTime(int64_t l, int64_t r) { return FindTime(l, r, 0); }

  int64_t FindTime(int64_t l, int64_t r, int64_t x) {
    if (l > datatime[x].rr || r < datatime[x].lr) {
      return 0;
    }
    if (l <= datatime[x].lr && r >= datatime[x].rr) {
      return datatime[x].time;
    }
    return FindTime(l, r, 2 * x + 1) + FindTime(l, r, 2 * x + 2);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  std::vector<OrderInfo> orders;
  int64_t N, Q, Start, End, Cost, Type;
  Tree tree{};

  cin >> N;

  for (int64_t i = 0; i < N; ++i) {
    cin >> Start >> End >> Cost;
    orders.push_back(OrderInfo{Start, End, End - Start, Cost});
  }

  tree.Construct(orders);

  cin >> Q;
  for (std::int64_t i = 0; i < Q; ++i) {
    cin >> Start >> End >> Type;
    if (Type == 1) {
      cout << tree.FindCost(Start, End) << '\n';
    } else {
      cout << tree.FindTime(Start, End) << '\n';
    }
  }
  return 0;
}