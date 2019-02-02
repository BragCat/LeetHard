class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.length(), n = key.length();
        vector<vector<int>> f(n, vector<int>(m, MAX_INT));
        for (int i = 0; i < m; ++i) {
            if (ring[i] == key[0]) {
                f[0][i] = min(i, m - i) + 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (key[i] == ring[j]) {
                    for (int k = 0; k < m; ++k) {
                        if (key[i - 1] == ring[k]) {
                            f[i][j] = min(f[i][j], f[i - 1][k] + min(abs(k - j), m - abs(k - j)) + 1);
                        }
                    }
                }
            }
        }
        return *min_element(f[n - 1].begin(), f[n - 1].end());
    }
private:
    const int MAX_INT = ~0u >> 1;
};