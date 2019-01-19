class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.length();
        if (n == 0) {
            return 0;
        }
        vector<vector<long long>> f(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            f[i][i] = 1;
        }
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i < n - l; ++i) {
                int j = i + l;
                if (S[i] == S[j]) {
                    int p = i + 1, q = j - 1;
                    while (p <= q && S[p] != S[i]) {
                        ++p;
                    }
                    while (p <= q && S[q] != S[j]) {
                        --q;
                    }
                    if (p > q) {
                        f[i][j] = (f[i + 1][j - 1] + f[i + 1][j - 1] + 2) % MODULO;
                    } else if (p == q) {
                        f[i][j] = (f[i + 1][j - 1] + f[i + 1][j - 1] + 1) % MODULO;
                    } else {
                        f[i][j] = (f[i + 1][j - 1] + f[i + 1][j - 1] - f[p + 1][q - 1] + MODULO) % MODULO;
                    }
                } else {
                    f[i][j] = (f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1] + MODULO) % MODULO;
                }
            }
        }
        return f[0][n - 1];
    }
private:
    const int MODULO = 1e9 + 7;
};