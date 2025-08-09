#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> used(baskets.size(), false);
        int unplaced = 0;

        for (int i = 0; i < fruits.size(); i++) {
            bool placed = false;
            for (int j = 0; j < baskets.size(); j++) {
                if (baskets[j] >= fruits[i] && !used[j]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) unplaced++;
        }
        return unplaced;
    }
};


/*
f = 3 6 1
b = 6 4 7

*/

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