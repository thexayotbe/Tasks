class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0); // 0: unvisited, 1: visiting, 2: safe
        vector<int> safeNodes;

        for (int i = 0; i < n; ++i) {
            if (dfs(i, graph, visited)) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }

private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[node] == 1) {
            return false; // Cycle detected
        }
        if (visited[node] == 2) {
            return true; // Already confirmed as safe
        }

        visited[node] = 1; // Mark as visiting
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, visited)) {
                return false; // If any neighbor is not safe, this node is not safe
            }
        }

        visited[node] = 2; // Mark as safe
        return true;
    }
};