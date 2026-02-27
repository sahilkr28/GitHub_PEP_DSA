// You are given a weighted undirected graph with n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between vertex 1 and vertex n. Each edge is given as {a, b, w}, denoting an edge between vertices a and b with weight w.

// If a path exists, return a list of integers where the first element is the total weight of the shortest path, and the remaining elements are the nodes along that path (from 1 to n). If no path exists, return a list containing only {-1}.

// Note: The driver code will internally verify your returned list.

// If both the path and its total weight are valid, only the total weight will be displayed as output.
// If your list contains only -1, the output will be -1.
// If the returned list is invalid, the output will be -2.
// Examples :

// Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
// Output: 5
// Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
// Input: n = 2, m= 1, edges = [[1, 2, 2]]
// Output: 2
// Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
// Input: n = 2, m= 0, edges = [ ]
// Output: -1
// Explanation: Since there are no edges, so no answer is possible.
// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n+m)

// Constraint:
// 2 <= n <= 106
// 0 <= m <= 106
// 1 <= a, b <= n
// 1 <= w <= 105

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<long long> dist(n+1, 1e18);
        vector<int> parent(n+1);
        
        for(int i = 1; i <= n; i++)
            parent[i] = i;
        
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;
        
        dist[1] = 0;
        pq.push({0,1});
        
        while(!pq.empty()) {
            pair<long long,int> top = pq.top();
            pq.pop();
            long long d = top.first;
            int node = top.second;
            
            if(d > dist[node]) continue;
            
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + wt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == 1e18)
            return {-1};
        
        vector<int> path;
        int node = n;
        
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        vector<int> ans;
        ans.push_back(dist[n]);
        
        for(auto &it : path)
            ans.push_back(it);
            
        return ans;
    }
};