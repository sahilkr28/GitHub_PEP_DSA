// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.

#include <bits/stdc++.h>
using namespace std;

// Topological Sort (Kahn's Algorithm)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build graph
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> q;
        
        // Push all nodes with indegree 0
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(int &neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        return count == numCourses;
    }
};

// DFS Approach
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        state[node] = 1;  // mark as visiting
        
        for(int neighbor : adj[node]) {
            if(state[neighbor] == 1) 
                return true;  // cycle detected
            
            if(state[neighbor] == 0) {
                if(dfs(neighbor, adj, state))
                    return true;
            }
        }
        
        state[node] = 2;  // mark as visited
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        // Build graph
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> state(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            if(state[i] == 0) {
                if(dfs(i, adj, state))
                    return false;
            }
        }
        
        return true;
    }
};