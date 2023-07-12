// There are a total of numCourses courses you have to take, labelled from 0 to numCourses - 1. You are given an array of prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have first to take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1, you should have finished course 0. So the correct course order is [0,1].
// Example 2:

// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3, you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So, one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
// Example 3:

// Input: numCourses = 1, prerequisites = []
// Output: [0]


class Solution {
public:

    bool topologicalSortDFS(int src, vector <int> adj[], vector <int>& ans, vector <bool> &visited, vector <bool>&srcVisited) {
        visited[src] = 1;
        srcVisited[src] = 1;

        for(auto i: adj[src]) {
            if(!visited[i]) {
                // it return true if we got any cycle in the graph
                if(topologicalSortDFS(i, adj, ans, visited, srcVisited)) return true;
            }
              // return true if there is cycle in graph
            else if(visited[i] && srcVisited[i]) {
                return true;
            }
        }

        ans.push_back(src);
        srcVisited[src] = 0;

      // return 0, if there is no cycle in graph
        return false;

    }

    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector <int> adj[n];
        vector <bool> visited(n, 0), srcVisited(n, 0);
        for(auto edge: preq) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector <int> ans;
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
              // if there is cycle in graph, then return empty vector
                if(topologicalSortDFS(i, adj, ans, visited, srcVisited)) return {};
            }
        }

      // return the topological sort for the given graph
        return ans;

        
    }
};
