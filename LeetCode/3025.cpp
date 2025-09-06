#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            int yA = points[i][1], maxY = INT_MIN;
            for (int j = i + 1; j < points.size(); j++) {
                int yB = points[j][1];
                if (maxY < yB && yB <= yA) {
                    maxY = yB;
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sol;
    
    return 0;
}