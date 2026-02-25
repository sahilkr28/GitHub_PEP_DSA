// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

// Note: The graph can have multiple component.

// Examples:

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation: 
 
// 1 -> 2 -> 0 -> 1 is a cycle.
// Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
// Output: false
// Explanation: 
 
// No cycle in the graph.
// Constraints:
// 1 ≤ V, E ≤ 105
// 0 ≤ edges[i][0], edges[i][1] < V

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                queue<pair<int,int>> q; // {node, parent}
                q.push({i, -1});
                visited[i] = 1;

                while (!q.empty()) {
                    pair<int,int> p = q.front();
                    q.pop();
                    int node = p.first;
                    int parent = p.second;

                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = 1;
                            q.push({neighbor, node});
                        }
                        else if (neighbor != parent) {
                            return true; // Cycle found
                        }
                    }
                }
            }
        }

        return false;
    }
};