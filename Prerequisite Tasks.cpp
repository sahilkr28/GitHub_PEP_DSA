// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of P prerequisite pairs, find if it is possible to finish all tasks.

// Examples:

// Input: N = 4, P = 3, prerequisites = [[1,0],[2,1],[3,2]]
// Output: Yes
// Explanation: To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1, and to do task 3 you should have finished task 2. So it is possible.
// Input: N = 2, P = 2, prerequisites = [[1,0],[0,1]]
// Output: No
// Explanation: To do task 1 you should have completed task 0, and to do task 0 you should have finished task 1. So it is impossible.
// Constraints:
// 1 ≤ N ≤ 104
// 1 ≤ P ≤ 105

#include <bits/stdc++.h>
using namespace std;

// Topological Sort (Kahn's Algorithm)
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);
        
        // Build graph
        for(auto &pr : prerequisites) {
            int u = pr.second;
            int v = pr.first;
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        
        // Push nodes with indegree 0
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        // Kahn's Algorithm
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(int &nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        
        return count == N;
    }
};

// DFS Approach
class Solution {
  public:
  
    bool dfs(int node, vector<vector<int>> &adj, 
             vector<bool> &visited, 
             vector<bool> &recStack) {
        
        visited[node] = true;
        recStack[node] = true;
        
        for(int &nbr : adj[node]) {
            
            // If not visited, recurse
            if(!visited[nbr]) {
                if(dfs(nbr, adj, visited, recStack))
                    return true;
            }
            // If visited AND in recursion stack → cycle
            else if(recStack[nbr]) {
                return true;
            }
        }
        
        recStack[node] = false;  // Backtrack
        return false;
    }
  
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        
        vector<vector<int>> adj(N);
        
        // Build graph
        for(auto &pr : prerequisites) {
            int u = pr.second;
            int v = pr.first;
            adj[u].push_back(v);
        }
        
        vector<bool> visited(N, false);
        vector<bool> recStack(N, false);
        
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, recStack))
                    return false;  // Cycle found
            }
        }
        
        return true;  // No cycle
    }
};