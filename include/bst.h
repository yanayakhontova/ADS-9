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
  Node *addNode(Node *root, T q) {
      if (root == nullptr) {
          root = new Node;
          root->val = q;
          root->lft = nullptr;
          root->rght = nullptr;
      } else {
          if (root->val > q) root->lft = addNode(root->lft, q);
          if (root->val < q) root->rght = addNode(root->rght, q);
          if (root->val == q) (root->count)++;
      }
      return root;
    }
  int searchValue(Node* root, T q) {
    if (root == nullptr) {
      return 0;
    } else if (root->val == q) {
        return root->count;
    } else if (root->val < q) {
        return searchValue(root->rght, q);
    } else {
        return searchValue(root->lft, q);
    }
  }
  int hght(Node* root) {
      if (root == nullptr)
        return 0;
      if (root->lft == nullptr && root->rght == nullptr) return 0;
      int rrt = hght(root->rght), lt = hght(root->lft);
      if (rrt > lt)
        return rrt + 1;
      else
        return lt + 1;
  }
 public:
  BST():root(nullptr) {}
  void add(T q) {
      root = addNode(root, q);
  }
  int depth() {
      return hght(root);
  }
  int search(T q) {
      return searchValue(root, q) + 1;
  }
};

#endif  // INCLUDE_BST_H_
