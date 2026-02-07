#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    bool isStar = false;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == n - 1) {
            isStar = true;
            break;
        }
    }
    if (isStar) {
        cout << 0 << "\n";
        return;
    }

    vector<int> subtreeSize(n + 1, 0);
    vector<int> leavesInSubtree(n + 1, 0);
    vector<ll> operationsNeeded(n + 1, 0);

    function<void(int, int)> dfs = [&](int node, int parent) {
        subtreeSize[node] = 1;
        leavesInSubtree[node] = (degree[node] == 1);
        operationsNeeded[node] = 0;

        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            dfs(neighbor, node);
            subtreeSize[node] += subtreeSize[neighbor];
            leavesInSubtree[node] += leavesInSubtree[neighbor];
            if (subtreeSize[neighbor] > 1) {
                operationsNeeded[node] += leavesInSubtree[neighbor];
            }
        }
    };

    dfs(1, 0);

    ll totalLeaves = leavesInSubtree[1];
    ll minOperations = LLONG_MAX;

    for (int node = 1; node <= n; ++node) {
        ll currentOps = operationsNeeded[node];

        if (node != 1) {
            ll parentComponentSize = n - subtreeSize[node];
            if (parentComponentSize > 1) {
                currentOps += (totalLeaves - leavesInSubtree[node]);
            }
        }

        minOperations = min(minOperations, currentOps);
    }

    cout << minOperations << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
