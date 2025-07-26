#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBan = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++) maxBan = max(maxBan, piles[i]);
        int l = 1, r = maxBan;

        while (l < r) {
            int mid = l + (r - l) / 2;
            int total = totalHours(piles, mid);

            if (total <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    int totalHours(vector<int>& piles, int k) {
        int total = 0;
        for (int i = 0; i < piles.size(); i++) {
            total += (piles[i] + k - 1) / k;
        }
        return total;
    }
};


int main() {
    int n, h;
    cin >> n >> h;

    vector<int> nums(n);
    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.minEatingSpeed(nums, h);
}