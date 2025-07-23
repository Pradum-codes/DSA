#include <bits/stdc++.h>
using namespace std;

const int MAXM = 3e5 + 10;
vector<int> tree[4 * MAXM];

// Add casino j to segment tree range [l, r]
void add(int node, int start, int end, int l, int r, int j) {
    if (l > end || r < start) return;
    if (l <= start && end <= r) {
        tree[node].push_back(j);
        return;
    }
    int mid = (start + end) / 2;
    add(2 * node, start, mid, l, r, j);
    add(2 * node + 1, mid + 1, end, l, r, j);
}

// Query casinos where range contains point p
vector<int> query(int node, int start, int end, int p) {
    if (start == end) return tree[node];
    int mid = (start + end) / 2;
    vector<int> res = tree[node];
    if (p <= mid) {
        vector<int> left = query(2 * node, start, mid, p);
        res.insert(res.end(), left.begin(), left.end());
    } else {
        vector<int> right = query(2 * node + 1, mid + 1, end, p);
        res.insert(res.end(), right.begin(), right.end());
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> l(n), r(n), real(n);
        vector<long long> vals;
        vals.push_back(k);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i] >> real[i];
            vals.push_back(l[i]);
            vals.push_back(r[i]);
            vals.push_back(real[i]);
        }

        // Discretize values
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();

        // Clear segment tree
        for (int i = 0; i < 4 * m; i++) tree[i].clear();

        // Build segment tree
        for (int j = 0; j < n; j++) {
            int rank_l = lower_bound(vals.begin(), vals.end(), l[j]) - vals.begin();
            int rank_r = lower_bound(vals.begin(), vals.end(), r[j]) - vals.begin();
            add(1, 0, m - 1, rank_l, rank_r, j);
        }

        // BFS
        vector<bool> visited(n, false);
        queue<int> q;
        long long max_real = k;

        // Start with casinos accessible from k
        int rank_k = lower_bound(vals.begin(), vals.end(), k) - vals.begin();
        vector<int> initial = query(1, 0, m - 1, rank_k);
        for (int j : initial) {
            if (!visited[j]) {
                q.push(j);
                visited[j] = true;
                max_real = max(max_real, real[j]);
            }
        }

        // Explore reachable casinos
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int rank_real = lower_bound(vals.begin(), vals.end(), real[i]) - vals.begin();
            vector<int> next = query(1, 0, m - 1, rank_real);
            for (int j : next) {
                if (!visited[j]) {
                    q.push(j);
                    visited[j] = true;
                    max_real = max(max_real, real[j]);
                }
            }
        }

        cout << max_real << "\n";
    }

    return 0;
}