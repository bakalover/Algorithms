#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <sys/types.h>
#include <vector>

void Split(std::vector<std::string> &ss, std::string s) {
  s.append(",");
  for (size_t j = 0, k = 0; j < s.length(); j++) {
    if (s[j] == ',') {
      ss.push_back(s.substr(k, j - k));
      k = j + 1;
    }
  }
}

size_t CountUnique(std::string s) {
  std::set<char> counter{};
  for (auto c : s) {
    counter.insert(c);
  }
  return counter.size();
}

size_t CountDayMonth(std::string s) {
  size_t count = 0;
  for (auto c : s) {
    count += (c - '0');
  }
  return count;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  size_t N;
  std::string input;
  std::cin >> N;

  for (size_t i = 0; i < N; ++i) {
    std::cin >> input;
    std::vector<std::string> data{};
    Split(data, input);
    size_t unique = CountUnique(data[0] + data[1] + data[2]);
    size_t daymonth = CountDayMonth(data[3] + data[4]);
    size_t al;
    if (data[0][0] > 'Z') {
      al = data[0][0] - 'a' + 1;
    } else {
      al = data[0][0] - 'A' + 1;
    }
    size_t res = unique + daymonth * 64 + 256 * al;
    std::stringstream stream;
    stream << std::hex << res;
    std::string result(stream.str());
    result = result.substr(result.length() - 3, 3);
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    std::cout << result << " ";
  }
}