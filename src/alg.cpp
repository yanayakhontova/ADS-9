// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include <string>
#include "bst.h"
BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;
    std::ifstream file(filename);
    if (!file) {
        throw std::string("file not found!");
    }
    std::string slovo = "";
    while (!file.eof()) {
        char chr = file.get();
        int sim = chr;
        if ((sim >= 65 && sim <= 90) || (sim >= 97 && sim <= 122)) {
            slovo += tolower(sim);
        } else {
            if (slovo != "") {
                tree.add(slovo);
                slovo = "";
            }
        }
    }
    file.close();
    return tree;
}
