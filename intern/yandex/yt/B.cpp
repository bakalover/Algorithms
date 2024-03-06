#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int search_first(string word, vector<string> &dict, int l, int r) {
  if(l <= r) {
    int mid = (l + r) / 2;
    if (dict[l].find(word) == 0) {
      return l;
    }else {
      
    }

  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, Q;
  string word;
  vector<string> dict;
  cin >> N >> Q;

  for (int i = 0; i < N; i++) {
    cin >> word;
    dict.push_back(word);
  }

  int n;
  string p;

  for (int i = 0; i < Q; i++) {
    cin >> n >> p;
  }

  return 0;
}
