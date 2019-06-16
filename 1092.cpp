class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, MIN_INT));
        vector<vector<pair<int, int>>> g(m + 1, vector<pair<int, int>>(n + 1, make_pair(-1, -1)));
        for (int i = 0; i < m; ++i) {
            f[i + 1][0] = 0;
        }
        for (int i = 0; i < n; ++i) {
            f[0][i + 1] = 0;
        }
        f[0][0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (str1[i] == str2[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1;
                    g[i + 1][j + 1] = {i, j};
                }
                if (f[i][j + 1] > f[i + 1][j + 1]) {
                    f[i + 1][j + 1] = f[i][j + 1];
                    g[i + 1][j + 1] = {i, j + 1};
                }
                if (f[i + 1][j] > f[i + 1][j + 1]) {
                    f[i + 1][j + 1] = f[i + 1][j];
                    g[i + 1][j + 1] = {i + 1, j};
                }
            }
        }
        string ans;
        int p = m, q = n;
        while (p > 0 && q > 0) {
            int np = g[p][q].first, nq = g[p][q].second;
            if (p - np == q - nq) {
                ans = str1[p - 1] + ans;
            } else if (p - np > 0) {
                ans = str1[p - 1] + ans;
            } else {
                ans = str2[q - 1] + ans;
            }
            p = np, q = nq;
        }
        if (p > 0) {
            ans = str1.substr(0, p) + ans;
        }
        if (q > 0) {
            ans = str2.substr(0, q) + ans;
        }
        return ans;
    }
private:
    const int MAX_INT = ~0u >> 1;
    const int MIN_INT = -MAX_INT - 1;
};