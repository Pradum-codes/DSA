#include "utils/bin_tree.h"
#include <iostream>

using namesspace std;
class Solution {
public:
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;

        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; i++) {
            auto leftTrees = build(start, i - 1);
            auto rightTrees = build(i + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};

int main(){
	TreeNode<int> root = nullptr;
	int n;

	Solution sol;
	
}
