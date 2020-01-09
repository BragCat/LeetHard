class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n, MAX_INT));
        for (int i = 0; i < n; ++i) {
            dp[0][i] = dp[1][i] = 0;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < n - i + 1; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + 1;
                if (s[j] == s[j + i - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 2][j + 1]);
                }
            }
        }
        return dp[n][0];
    }
private:
    const int MAX_INT = ~0u >> 1;
};