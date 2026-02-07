#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nxt;
        stack<int> st;

        // Step 1: preprocess nums2
        for (int x : nums2) {
            while (!st.empty() && st.top() < x) {
                nxt[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        // Step 2: answer queries for nums1
        vector<int> res;
        for (int x : nums1) {
            res.push_back(nxt.count(x) ? nxt[x] : -1);
        }

        return res;
    }
};


// BRUTE FORCE

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();

//         vector<int> res;
//         for(int i = 0; i<n; i++) {
//             int ind = 0;
//             for(int j = 0; j<m; j++) {
//                 if (nums1[i] == nums2[j]) {
//                     ind = j;
//                     break;
//                 }
//             }
//             if(ind == m) {
//                 res.push_back(-1);
//             } else {
//                 bool found = false;
//                 for(int j = ind+1; j<m; j++) {
//                     if(nums2[j] > nums1[i]){
//                         res.push_back(nums2[j]);
//                         found = true;
//                         break;
//                     }
//                 }
//                 if(!found) res.push_back(-1);
//             }
//         }

//         return res;
//     }
// };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for(int i = 0; i<n; i++) cin >> nums1[i];
    for(int i = 0; i<m; i++) cin >> nums2[i];

    Solution sol;
    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    return 0;
}