#include <algorithm>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <vector>

struct Node {
  int64_t val, counter = 0;
};

class Heap {
public:
  void push(Node *el) {
    elements.push_back(el);
    siftup(n++);
  }

  Node *extract_max() {
    --n;
    std::swap(elements[0], elements[n]);
    Node *el = elements.back();
    elements.pop_back();
    siftdown(0);
    return el;
  }

  void siftup(int32_t i) {
    while (i > 0 && elements[parent(i)]->counter < elements[i]->counter) {
      std::swap(elements[i], elements[parent(i)]);
      i = parent(i);
    }
  }
  void siftdown(int32_t i) {
    int32_t j = i;
    while (true) {
      if (left(i) < n && elements[j]->counter <= elements[left(i)]->counter) {
        j = left(i);
      }
      if (right(i) < n && elements[j]->counter <= elements[right(i)]->counter) {
        j = right(i);
      }
      if (i == j)
        break;
      std::swap(elements[i], elements[j]);
      i = j;
    }
  }

  int32_t parent(int32_t i) { return (i - 1) / 2; }

  int32_t left(int32_t i) { return 2 * i + 1; }

  int32_t right(int32_t i) { return 2 * i + 2; };

private:
  size_t n = 0;
  std::vector<Node *> elements;
};

int main() {
  int64_t N;
  std::cin >> N;
  for (int64_t i = 0; i < N; ++i) {
  }
}