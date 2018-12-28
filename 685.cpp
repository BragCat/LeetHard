class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> nodeEdges(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            --edges[i][0], --edges[i][1];
            nodeEdges[edges[i][0]].push_back(edges[i][1]);
        }
        for (int i = n - 1; i >= 0; --i) {
            vector<int> degree(n, 0);
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    ++degree[edges[j][1]];
                }
            }
            int root = -1, cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (degree[j] == 0) {
                    root = j;
                    ++cnt;
                }
            }
            if (cnt != 1) {
                continue;
            }
            
            vector<bool> searched(n, false);
            if (dfs(nodeEdges, searched, root, edges[i][0], edges[i][1]) == n) {
                return {edges[i][0] + 1, edges[i][1] + 1};
            }
        }
        return vector<int>();
    }
private:
    int dfs(vector<vector<int>> &nodeEdges, vector<bool> &searched, int node, int u, int v) {
        int cnt = 1;
        searched[node] = true;
        for (int i = 0; i < nodeEdges[node].size(); ++i) {
            if (!searched[nodeEdges[node][i]] && (node != u || nodeEdges[node][i] != v)) {
                cnt += dfs(nodeEdges, searched, nodeEdges[node][i], u, v);
            }
        }
        return cnt;
    }
};