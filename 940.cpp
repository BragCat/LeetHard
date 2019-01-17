class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.length(); 
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0)), g(n + 1, vector<int>(n + 1, 0));
        f[0][0] = 1;
        for (int j = 0; j <= n; ++j) {
            g[j][0] = 1;
        }
        int ans = 0;
        map<char, int> lastIndex;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= i + 1; ++j) {
                int k = lastIndex[S[i]];
                if (k == 0) {
                    f[i + 1][j] = g[i][j - 1];
                } else {

                    f[i + 1][j] = (g[i][j - 1] + MODULO - g[k - 1][j - 1]) % MODULO;
                }
                g[i + 1][j] = (g[i][j] + f[i + 1][j]) % MODULO;
                ans = (ans + f[i + 1][j]) % MODULO;
            }
            lastIndex[S[i]] = i + 1;
        } 
        return ans;
    }
private:
    const int MODULO = 1e9 + 7;
};
