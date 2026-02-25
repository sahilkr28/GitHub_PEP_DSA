// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
// The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from vertex u to v.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]



// Output: true
// Explanation: The diagram clearly shows a cycle 0 → 1 → 2 → 0
// Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]


// Output: false
// Explanation: no cycle in the graph
// Constraints:
// 1 ≤ V ≤ 105
// 0 ≤ E ≤ 105
// 0 ≤ edges[i][0], edges[i][1] < V

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        
        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        
        // Push nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        // Kahn's BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        
        // If not all nodes processed → cycle
        return count != V;
    }
};