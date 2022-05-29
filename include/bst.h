// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template<typename T>

class BST {
 private:
  struct Node {
    T val;
    Node *right;
    Node *left;
    int cnt;
  };
  Node *root;
  Node *addNode(Node *root, T x) {
      if (root == nullptr) {
          root = new Node;
          root->val = x;
          root->left = nullptr;
          root->right = nullptr;
      } else {
          if (root->val > x) root->left = addNode(root->left, x);
          if (root->val < x) root->right = addNode(root->right, x);
          if (root->val == x) (root->cnt)++;
      }
      return root;
    }

  int searchValue(Node* root, T x) {
    if (root == nullptr) {
      return 0;
    } else if (root->val == x) {
        return root->cnt;
    } else if (root->val < x) {
        return searchValue(root->right, x);
    } else {
        return searchValue(root->left, x);
    }
  }

  int height(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->left == nullptr && root->right == nullptr) return 0;
      int rrtt = height(root->right), lltt = height(root->left);
      if (rrtt > lltt)
        return rrtt + 1;
      else
        return lltt + 1;
  }

 public:
  BST():root(nullptr) {}
  void add(T x) {
      root = addNode(root, x);
  }
  int depth() {
      return height(root);
  }
  int search(T x) {
      return searchValue(root, x) + 1;
  }
};

#endif  // INCLUDE_BST_H_


