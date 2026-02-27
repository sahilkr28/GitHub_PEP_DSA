// Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
// You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

// Note: The Graph is connected and doesn't contain any negative weight edge.
// It is guaranteed that all the shortest distance will fit in a 32-bit integer.

// Examples:

// Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
// Output: [4, 3, 0]
// Explanation:

// Shortest Paths:
// For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
// For 2 to 1 minimum distance will be 3. By following path 2 -> 1
// For 2 to 2 minimum distance will be 0. By following path 2 -> 2
// Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
// Output: [0, 4, 8, 10, 10]
// Explanation: 

// Shortest Paths: 
// For 0 to 1 minimum distance will be 4. By following path 0 -> 1
// For 0 to 2 minimum distance will be 8. By following path 0 -> 2
// For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
// For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
// Constraints:
// 1 ≤ V ≤ 106
// 1 ≤ E = edges.size() ≤ 106
// 0 ≤ edges[i][0], edges[i][1] ≤ V-1
// 0 ≤ edges[i][2] ≤ 104
// 0 ≤ src < V

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        
        // Build adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;
        
        pq.push({0, src});
        
        while(!pq.empty()){
            
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(d > dist[node]) continue;
            
            for(auto &it : adj[node]){
                int adjNode = it.first;
                int weight = it.second;
                
                if(dist[node] + weight < dist[adjNode]){
                    dist[adjNode] = dist[node] + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};