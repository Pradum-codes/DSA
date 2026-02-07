#include "utils/bin_tree.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode<int>* p, TreeNode<int>* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};


int main(){
	TreeNode<int>* t1 = nullptr;
	TreeNode<int>* t2 = nullptr;

	int n; cin >> n;
	for(int i = 0; i<n; i++){
		int d; cin >> d;
		t1 = insertNode(t1, d);
	}

	for(int i = 0; i<n; i++){
		int d; cin >> d;
		t2 = insertNode(t2, d);
	}

	Solution sol;
	if(sol.isSameTree(t1, t2)) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
	return 0;	
}
