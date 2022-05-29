// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
template<typename T>
class BST {
 private:
  struct Node {
    T val;
    Node *rght;
    Node *lft;
    int count;
  };
  Node *root;
  Node *addNode(Node *root, T x) {
      if (root == nullptr) {
          root = new Node;
          root->val = x;
          root->lft = nullptr;
          root->rght = nullptr;
      } else {
          if (root->val > x) root->lft = addNode(root->lft, x);
          if (root->val < x) root->rght = addNode(root->rght, x);
          if (root->val == x) (root->count)++;
      }
      return root;
    }
  int searchValue(Node* root, T x) {
    if (root == nullptr) {
      return 0;
    } else if (root->val == x) {
        return root->count;
    } else if (root->val < x) {
        return searchValue(root->rght, x);
    } else {
        return searchValue(root->lft, x);
    }
  }
  int hght(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->lft == nullptr && root->rght == nullptr) return 0;
      int rt = hght(root->rght), lt = hght(root->lft);
      if (rt > lt)
        return rt + 1;
      else
        return lt + 1;
  }
 public:
  BST():root(nullptr) {}
  void add(T x) {
      root = addNode(root, x);
  }
  int depth() {
      return hght(root);
  }
  int search(T x) {
      return searchValue(root, x) + 1;
  }
};

#endif  // INCLUDE_BST_H_

