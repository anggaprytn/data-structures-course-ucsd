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

bool IsBSTUtil(const vector<Node>& tree, int node, int& prev) {
  if (node == -1) return true; // An empty subtree is a BST

  // Check the left subtree
  if (!IsBSTUtil(tree, tree[node].left, prev)) return false;

  // Check the current node: it must be greater than the previous node's key
  if (tree[node].key <= prev) return false;
  prev = tree[node].key;

  // Check the right subtree
  return IsBSTUtil(tree, tree[node].right, prev);
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  if (tree.empty()) return true; // An empty tree is a BST
  int prev = std::numeric_limits<int>::min();
  return IsBSTUtil(tree, 0, prev);
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
