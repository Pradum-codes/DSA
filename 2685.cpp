#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        void buildGraph(int n, vector<vector<int>>& edges, vector<vector<int>>& adj) {
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    
        void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
            visited[node] = true;
            component.push_back(node);
        
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor, adj, visited, component);
                }
            }
        }
    
        bool isComplete(vector<int>& component, vector<vector<int>>& adj) {
            int k = component.size();
            int edgeCount = 0;
    
            for (int node : component) {
                edgeCount += adj[node].size();
            }
        
            edgeCount /= 2;
            return edgeCount == (k * (k - 1)) / 2;
        }
    
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            vector<bool> visited(n, false);
            int completeComponents = 0;
    
            buildGraph(n, edges, adj);
    
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    vector<int> component;
                    dfs(i, adj, visited, component);
    
                    if (isComplete(component, adj)) {
                        completeComponents++;
                    }
                }
            }
            
            return completeComponents;
        }
    };

int main() {
    Solution obj;

    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    cout << "Output: " << obj.countCompleteComponent(6, edges1) << endl; // Expected: 3

    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    cout << "Output: " << obj.countCompleteComponent(6, edges2) << endl; // Expected: 1

    return 0;
}
