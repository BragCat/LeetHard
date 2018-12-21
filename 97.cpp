class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len3 != len1 + len2) {
            return false;
        }
        
        vector<vector<bool>> f(len3 + 1, vector<bool>(len1 + 1, false));
        f[0][0] = true;
        for (int i = 1; i <= len3; ++i) {
            for (int j = 0; j <= min(i, len1); ++j) {
                if (i - j > len2) {
                    continue;
                }
                if (j > 0 && s3[i - 1] == s1[j - 1]) {
                    f[i][j] = f[i - 1][j - 1];
                }
                if (i - j > 0 && s3[i - 1] == s2[i - j - 1]) {
                    f[i][j] = f[i][j] || f[i - 1][j];
                }
            }
        }
        return f[len3][len1];
    }
};