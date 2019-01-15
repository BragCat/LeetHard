class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> f(n, vector<int>(n, MAX_INT));
        for_each(f[0].begin(), f[0].end(), [](auto &x) {x = 1;});
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                for (int k = j; k < j + i; ++k) {
                    f[i][j] = min(f[i][j], f[k - j][j] + f[j + i - k - 1][k + 1] + ((s[k] == s[j + i]) ? -1 : 0));
                }
            }
        }
        return f[n - 1][0];
    }
private:
    const int MAX_INT = ~0u >> 1;
};