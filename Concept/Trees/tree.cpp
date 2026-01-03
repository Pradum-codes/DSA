#include "utils/bin_tree.h"
#include <iostream>

int main() {
    TreeNode<int>* root = nullptr;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int d;
        std::cin >> d;
        root = insertNode(root, d);
    }

    inorder(root);
    std::cout << std::endl;
}
