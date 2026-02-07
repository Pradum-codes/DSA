#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n <= 2) return n;

        unordered_map<int, int> mp;
        int maxFruits = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            mp[fruits[right]]++;

            while (mp.size() > 2) {
                mp[fruits[left]]--;
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> fruits(n);
    for(int i = 0; i<n; i++) cin >> fruits[i];

    Solution sol;
    cout << sol.totalFruit(fruits) << endl;
    return 0;
}