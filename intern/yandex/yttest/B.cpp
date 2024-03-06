#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <utility>
#include <vector>

struct RocketData {
  size_t timestamp;
  std::string state;
};

size_t CalcTime(std::vector<RocketData> &data) {
  size_t res = 0;
  size_t curr = 0;
  std::sort(data.begin(), data.end(), [](RocketData &x, RocketData &y) {
    return x.timestamp < y.timestamp;
  });

  for (size_t i = 0; i < data.size(); ++i) {
    if (data[i].state == "A") {
      curr = data[i].timestamp;
    } else if (data[i].state == "B") {
      res += (data[i].timestamp - curr);
      curr = data[i].timestamp;
    } else {
      res += (data[i].timestamp - curr);
      curr = 0;
    }
  }
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  size_t N, day, hour, minute, id;
  std::string state;
  std::cin >> N;
  std::map<size_t, std::vector<RocketData>> data;

  for (size_t i = 0; i < N; ++i) {
    std::cin >> day >> hour >> minute >> id >> state;
    data[id].push_back(RocketData{day * 24 * 60 + hour * 60 + minute, state});
  }

  std::map<size_t, size_t> res;
  for (auto a : data) {
    res[a.first] = CalcTime(a.second);
  }
  for (auto a : res) {
    std::cout << a.second << " ";
  }

  //   std::cout << "----------------------------------" << std::endl;
  //   for (auto rocket : data) {
  //     std::cout << rocket.day << " " << rocket.hour << " " << rocket.minute
  //     << " "
  //               << rocket.id << " " << rocket.state << std::endl;
  //   }
}