#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicate(vector<int>& arr) {
        set<int> s;
        for(int num : arr) s.insert(num);
        
        vector<int> res;
        for(auto num : s) res.push_back(num);
        
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;

    vector<int> arr(n);       
    for(int i = 0; i<n; i++) cin >> arr[i];

    Solution sol;
    vector<int> res = sol.removeDuplicate(arr);

    for(int i = 0; i<res.size(); i++) cout << res[i] << " ";
    cout << endl;
    
    return 0;
}