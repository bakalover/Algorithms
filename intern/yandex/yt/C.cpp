#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <new>
#include <set>
#include <string>
#include <sys/types.h>
#include <utility>
#include <vector>

using namespace std;

struct Node {
  Node *parent;
  vector<Node *> children{27};
  int prio = 0;
  int n = 0;
};

class Tree {
private:
  Node *root, *cur;

public:
  Tree() {
    root = new Node();
    cur = root;
  }

  void Insert(string word, int prio, int n) {
    Node *current = root;

    for (char c : word) {
      int index = c - 'a';
      if (current->children[index] == nullptr) {
        current->children[index] = new Node();
        current->children[index]->parent = current;
      }
      if (current->prio < prio) {
        current->prio = prio;
        current->n = n;
      }
      current = current->children[index];
    }
    current->n = n;
    current->prio = prio;
  }

  int Add(char c) {
    int index = c - 'a';
    if (cur->children[index] == nullptr) {
      return -1;
    }
    cur = cur->children[index];
    return cur->n;
  }

  int Remove() {
    cur = cur->parent;
    return cur->n;
  }
};

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  string addreq;
  char changereq, ch;
  int prio;

  Tree tree{};

  for (int i = 0; i < N; ++i) {
    cin >> addreq >> prio;
    tree.Insert(addreq, prio, i + 1);
  }
  for (int i = 0; i < Q; ++i) {
    cin >> changereq;
    if (changereq == '-') {
      cout << tree.Remove() << "\n";
    } else {
      cin >> ch;
      cout << tree.Add(ch) << "\n";
    }
  }
  return 0;
}

// 4 6
// yandex 10
// yacht 1
// yoghurt 15
// yyyy 50
// + y
// + a
// + n
// -
// -
// + o
// -
// + y
// + y
// + y