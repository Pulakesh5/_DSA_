class Solution {
public:
    bool isCyclic(vector<vector<int>> &dep) {
        int V = dep.size();
        vector<int> inDegree(V, 0); // stores in-degree of each vertex
        queue<int> q; // queue to store vertices with 0 in-degree
        int visited = 0; // count of visited vertices
 
        // calculate in-degree of each vertex
        for (int u = 0; u < V; u++) {
            for (auto v : dep[u]) {
                inDegree[v]++;
            }
        }
 
        // enqueue vertices with 0 in-degree
        for (int u = 0; u < V; u++) {
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
 
        // BFS traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visited++;
 
            // reduce in-degree of adjacent vertices
            for (auto v : dep[u]) {
                inDegree[v]--;
                // if in-degree becomes 0, enqueue the vertex
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
 
        return visited != V; // if not all vertices are visited, there is a cycle
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;
        vector<vector<int>> dep(N);

        for(auto v:prerequisites)
            dep[v[0]].push_back(v[1]);

        return !isCyclic(dep);
    }
};
