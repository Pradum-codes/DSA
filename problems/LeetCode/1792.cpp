#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto delta = [](double p, double t) {
            return (p + 1) / (t + 1) - p / t;
        };

        priority_queue<array<double, 3>> pq;

        for (auto& c : classes) {
            double p = c[0], t = c[1];
            pq.push({delta(p, t), p, t});
        }

        while (extraStudents--) {
            auto [gain, p, t] = pq.top();
            pq.pop();
            p += 1;
            t += 1;
            pq.push({delta(p, t), p, t});
        }

        double sum = 0.0;
        while (!pq.empty()) {
            auto [_, p, t] = pq.top();
            pq.pop();
            sum += p / t;
        }

        return sum / classes.size();
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sol;
    
    return 0;
}