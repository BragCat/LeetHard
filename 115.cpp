class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.length(), lent = t.length();
        if (lens == 0 || lent == 0) {
            return 0;
        }
        vector<vector<int>> f(lent + 1, vector<int>(lens + 1, 0)), sum(lent + 1, vector<int>(lens + 1, 0));
        f[0][0] = 1;
        for (int j = 1; j <= lens; ++j) {
            sum[0][j] = sum[0][j - 1] + f[0][j - 1];
        }
        for (int i = 1; i <= lent; ++i) {
            for (int j = i; j <= lens; ++j) {
                if (t[i - 1] == s[j  - 1]) {
                    f[i][j] = sum[i - 1][j];    
                }
                sum[i][j] = sum[i][j - 1] + f[i][j - 1];
            }
        }
        return accumulate(f[lent].begin(), f[lent].end(), 0);
    }
};