#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool IsBSTUtil(const vector<Node>& tree, int node, int min, int max) {
  if (node == -1) return true; // An empty subtree is a BST

  if (tree[node].key < min || tree[node].key > max) return false; // Violation of BST properties

  return IsBSTUtil(tree, tree[node].left, min, tree[node].key - 1) &&
         IsBSTUtil(tree, tree[node].right, tree[node].key + 1, max);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  if (tree.empty()) return true; // An empty tree is a BST
  return IsBSTUtil(tree, 0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
