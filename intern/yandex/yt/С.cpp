#include <array>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>

// size_t BinSize(size_t n) {
//   size_t actual_size = 1;
//   while (actual_size < n) {
//     actual_size *= 2;
//   }
//   return actual_size;
// }

struct Node {
  size_t value;
  Node *p = nullptr, *l = nullptr, *r = nullptr;
};

size_t GetParent(size_t v) { return v / 2; }
size_t RightChild(size_t v) { return 2 * v + 1; }
size_t LeftChild(size_t v) { return 2 * v; }
bool IsRoot(Node *v) { return v == v->p; }
bool HaveLeftChild(Node *v) { return v->l != nullptr; }
bool HaveRightChild(Node *v) { return v->r != nullptr; }
bool IsRightChild(Node *v) {
  if (HaveRightChild(v->p)) {
    return v->p->r->value == v->value;
  }
  return false;
}
void SetUpGrand(Node *dad, Node *boy, Node *grand) {
  if (IsRoot(dad)) {
    boy->p = boy;
    return;
  }
  if (IsRightChild(dad)) {
    grand->r = boy;
  } else {
    grand->l = boy;
  }
  boy->p = grand;
}

void RotateRight(Node *v) {
  // Fixed positions
  Node *boy = v, *rightboy = v->r, *dad = v->p, *grand = v->p->p;
  SetUpGrand(dad, boy, grand);

  if (HaveRightChild(v)) {
    rightboy->p = dad;
  }
  dad->r = rightboy;
  boy->r = dad;
  dad->p = boy;
}
void RotateLeft(Node *v) {
  // Fixed positions
  Node *boy = v, *leftboy = v->l, *dad = v->p, *grand = v->p->p;
  SetUpGrand(dad, boy, grand);
  if (HaveLeftChild(v)) {
    leftboy->p = dad;
  }
  dad->l = leftboy;
  boy->l = dad;
  dad->p = boy;
}

void PrintLVR(Node *v) {
  if (v->l != nullptr) {
    PrintLVR(v->l);
  }
  std::cout << v->value << " ";
  if (v->r != nullptr) {
    PrintLVR(v->r);
  }
}

int main() {
  size_t N, Q, v_i;
  std::cin >> N >> Q;
  std::vector<Node> tree{N + 1};

  // Initial linking
  for (size_t i = 1; i <= N; ++i) {
    // Always safe
    tree[i].value = i;
    tree[i].p = &tree[GetParent(tree[i].value)];
    if (LeftChild(tree[i].value) <= N) {
      tree[i].l = &tree[LeftChild(tree[i].value)];
    }
    if (RightChild(tree[i].value) <= N) {
      tree[i].r = &tree[RightChild(tree[i].value)];
    }
  }
  tree[1].p = &tree[1];
  // tree[0].p = &tree[0];
  // 10 6 5 7 4 7 8 7
  for (size_t i = 0; i < Q; ++i) {
    std::cin >> v_i;
    Node *node = &tree[v_i];
    if (IsRoot(node)) {
      continue;
    }
    if (IsRightChild(node)) {
      RotateRight(node);

    } else {
      RotateLeft(node);
    }
  }

  Node *root;
  for (size_t i = 1; i <= N; ++i) {
    if (tree[i].p == &tree[i]) {
      root = &tree[i];
      break;
    }
  }
  PrintLVR(root);
}