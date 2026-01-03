#pragma once
#include <iostream>

template <typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// ---------- INSERT (BST) ----------
template <typename T>
TreeNode<T>* insertNode(TreeNode<T>* root, const T& data) {
    if (!root) return new TreeNode<T>(data);

    if (data < root->val)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

// ---------- MIN / MAX ----------
template <typename T>
T findMin(TreeNode<T>* root) {
    if (!root) throw std::runtime_error("Empty tree");
    while (root->left) root = root->left;
    return root->val;
}

template <typename T>
T findMax(TreeNode<T>* root) {
    if (!root) throw std::runtime_error("Empty tree");
    while (root->right) root = root->right;
    return root->val;
}

// ---------- TRAVERSALS ----------
template <typename T>
void inorder(TreeNode<T>* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

template <typename T>
void preorder(TreeNode<T>* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

template <typename T>
void postorder(TreeNode<T>* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}
