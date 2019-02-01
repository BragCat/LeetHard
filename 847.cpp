class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> dist(n, vector<int>(n, MAX_INT));
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                dist[i][graph[i][j]] = dist[graph[i][j]][i] = 1;
            }
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (i != k && dist[i][k] != MAX_INT) {
                    for (int j = 0; j < n; ++j) {
                        if (i != j && k != j & dist[k][j] != MAX_INT) {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> f(n, vector<int>(1 << n, MAX_INT));
        for (int i = 0; i < n; ++i) {
            f[i][1 << i] = 0;
        }
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if ((1 << j) & i) {
                    for (int k = 0; k < n; ++k) {
                        if (k != j && ((1 << k) & i)) {
                            f[j][i] = min(f[j][i], f[k][i ^ (1 << j)] + dist[k][j]); 
                        }
                    }
                }
            }
        }
        int ans = MAX_INT;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, f[i][(1 << n) - 1]);
        }
        return ans;
    }
private:
    const int MAX_INT = ~0u >> 1;
};