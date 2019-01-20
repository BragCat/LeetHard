class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) {
            return 0;
        }
        int n = routes.size();
        vector<int> stNodes, edNodes;
        vector<vector<int>> d(n + 2, vector<int>(n + 2, MAX_INT));
        for (int i = 0; i < n; ++i) {
            d[i][i] = 0;    
            sort(routes[i].begin(), routes[i].end());
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int p = 0, q = 0;
                while (p != routes[i].size() && q != routes[j].size()) {
                    if (routes[i][p] == routes[j][q]) {
                        d[i][j] = d[j][i] = 1;
                        break;
                    }
                    while (p < routes[i].size() && routes[i][p] < routes[j][q]) {
                        ++p;
                    }
                    while (q < routes[j].size() && routes[j][q] < routes[i][p]) {
                        ++q;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                if (routes[i][j] == S) {
                    d[n][i] = d[i][n] = 1;
                    break;
                }
            }
            for (int j = 0; j < routes[i].size(); ++j) {
                if (routes[i][j] == T) {
                    d[i][n + 1] = d[n + 1][i] = 1;
                    break;
                }
            }
        }
        for (int k = 0; k < n + 2; ++k) {
            for (int i = 0; i < n + 2; ++i) {
                if (i != k && d[i][k] != MAX_INT) {
                    for (int j = 0; j < n + 2; ++j) {
                        if (j != i && j != k && d[k][j] != MAX_INT) {
                            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                        }
                    }
                }
            }
        }
        if (d[n][n + 1] == MAX_INT) {
            return -1;
        } else {
            return d[n][n + 1] - 1;
        }
    }
private:
    const int MAX_INT = ~0u >> 1;
};