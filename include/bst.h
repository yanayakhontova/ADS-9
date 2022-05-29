// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>
template <typename t>
struct node {
    node<t>* right = nullptr;
    node<t>* left = nullptr;
    node<t>* prev = nullptr;
    int cnt = 0;
    t value = "";
};
template <typename t>
class BST {
 private:
    node<t>* root = nullptr;
    int hght = 0;
    void getdepth(node<t>* tree, int x) {
        ++x;
        if (tree->left != nullptr) {
            getdepth(tree->left, x);
        }
        if (tree->right != nullptr) {
            getdepth(tree->right, x);
        }
        if (x > hght) {
            hght = x;
        }
    }
    void delnode(node<t>* node) {
        if (node->left != nullptr) {
            delnode(node->left);
        }
        if (node->right != nullptr) {
            delnode(node->right);
        }
        delete node;
    }
 public:
    BST() {
        root = nullptr;
        hght = 0;
    }
    ~BST() {
        delnode(root);
    }
    void add(t item) {
        node<t>* cur = root;
        node<t>* prev = nullptr;
        int ps = 0;
        while (true) {
            if (cur == nullptr) {
                cur = new node<t>;
                cur->left = nullptr;
                cur->right = nullptr;
                cur->value = item;
                cur->cnt = 1;
                if (prev != nullptr) {
                    cur->prev = prev;
                    if (ps == 1) {
                        prev->right = cur;
                    } else {
                        prev->left = cur;
                    }
                    ps = 0;
                    prev = nullptr;
                }
                if (root == nullptr) {
                    root = cur;
                }
                break;
            }
            if (cur->value < item) {
                prev = cur;
                ps = 1;
                cur = cur->right;
            } else if (cur->value == item) {
                cur->cnt++;
                break;
            } else {
                prev = cur;
                ps = -1;
                cur = cur->left;
            }
        }
    }
    int search(t item) {
        node<t>* cur = root;
        while (true) {
            if (cur == nullptr) {
                throw std::string("tree is empty!");
            } else if (cur->value < item) {
                cur = cur->right;
            } else if (cur->value == item) {
                return cur->cnt;
            } else {
                cur = cur->left;
            }
        }
    }
    int depth() {
        node<t>* cur = root;
        getdepth(cur, 0);
        return hght - 1;
    }
};
#endif  // INCLUDE_BST_H_


