#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(arr, node*2, l, mid);
        build(arr, node*2+1, mid+1, r);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }

    int query(int node, int l, int r, int fruit) {
        if (tree[node] < fruit) return -1; // no basket here
        if (l == r) return l; // found the basket
        int mid = (l+r)/2;
        int left = query(node*2, l, mid, fruit);
        if (left != -1) return left;
        return query(node*2+1, mid+1, r, fruit);
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node] = -1e9; // mark as used
            return;
        }
        int mid = (l+r)/2;
        if (idx <= mid) update(node*2, l, mid, idx);
        else update(node*2+1, mid+1, r, idx);
        tree[node] = max(tree[node*2], tree[node*2+1]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree st(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            int idx = st.query(1, 0, baskets.size()-1, fruit);
            if (idx == -1) unplaced++;
            else st.update(1, 0, baskets.size()-1, idx);
        }
        return unplaced;
    }    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> fruits(n), basket(n);
    for(int i = 0; i<n; i++) cin >> fruits[i];
    for(int i = 0; i<n; i++) cin >> basket[i];

    Solution sol;
    cout << sol.numOfUnplacedFruits(fruits, basket) << endl;
    return 0;
}