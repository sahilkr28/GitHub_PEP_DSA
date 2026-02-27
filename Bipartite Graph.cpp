// Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

// A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:

// All edges connect vertices from one set to vertices in the other set.
// No edges exist between vertices within the same set.
// Examples:

// Input: V = 3, edges[][] = [[0, 1], [1,2]]
// Bipartite-Graph
// Output: true
// Explanation: The given graph can be colored in two colors so, it is a bipartite graph.
// Input: V = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]




// Output: false 
// Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs. 
// Constraints:
// 1 ≤ V ≤ 2 * 105
// 1 ≤ edges.size() ≤ 105
// 1 ≤ edges[i][j] ≤ 105

#include <bits/stdc++.h>
using namespace std;

// BFS Approach
class Solution {
public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        // Build undirected graph
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1); // -1 = uncolored
        
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int nei : adj[node]) {
                        if (color[nei] == -1) {
                            color[nei] = 1 - color[node];
                            q.push(nei);
                        }
                        else if (color[nei] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

// DFS Approach     
class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = col;
        
        for (int nei : adj[node]) {
            if (color[nei] == -1) {
                if (!dfs(nei, 1 - col, adj, color))
                    return false;
            }
            else if (color[nei] == col) {
                return false;
            }
        }
        
        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        
        // Undirected graph
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1); // -1 = uncolored
        
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }
        
        return true;
    }
};