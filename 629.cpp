class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> f(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> g(n + 1, vector<int>(k + 1, 0));
        f[1][0] = 1;
        g[1] = vector<int>(k + 1, 1);
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (j > (i * (i - 1) / 2)) {
                    f[i][j] = 0;
                } else {
                    f[i][j] = g[i - 1][j];
                    if (j - i >= 0) {
                        f[i][j] = (f[i][j] + MODULO - g[i - 1][j - i]) % MODULO;
                    }
                }
            }
            g[i][0] = f[i][0];
            for (int j = 1; j <= k; ++j) {
                g[i][j] = (g[i][j - 1] + f[i][j]) % MODULO;
            }
        }
        return f[n][k];
    } 
private:
    const int MODULO = 1e9 + 7;
};