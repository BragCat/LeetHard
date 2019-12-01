class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, MAX_INT));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int l = 0; l < i; ++l) {
                    if (dp[l][j - 1] != MAX_INT) {
                        dp[i][j] = min(dp[i][j], dp[l][j - 1] + min_replace(s.substr(l, i - l)));
                    }
                }
                //cout << i - 1 << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        return dp[n][k];
    }
private:
    const int MAX_INT = ~0u >> 1;
    int min_replace(string s) {
        int n = s.length();
        int l, r;
        if (n % 2 == 0) {
            l = n / 2 - 1, r = l + 1;
        } else {
            l = r = n / 2;
        }
        int cnt = 0;
        while (l >= 0 && r < n) {
            if (s[l] != s[r]) {
                ++cnt;
            }
            --l, ++r;
        }
        return cnt;
    }
};