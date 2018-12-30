class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 != len2) {
            return false;
        }
        vector<vector<vector<bool>>> f(len1, vector<vector<bool>>(len2, vector<bool>(len1 + 1, false)));
        for (int k = 1; k <= len1; ++k) {
            for (int i = 0; i <= len1 - k; ++i) {
                for (int j = 0; j <= len2 - k; ++j) {
                    f[i][j][k] = s1.substr(i, k) == s2.substr(j, k);
                    for (int l = 1; l < k; ++l) {
                        f[i][j][k] = f[i][j][k] || (f[i][j][l] && f[i + l][j + l][k - l]);
                    }
                    for (int l = j + 1; l < j + k; ++l) {
                        f[i][j][k] = f[i][j][k] || (f[i][l][k - (l - j)] && f[i + k - (l - j)][j][l - j]);
                    }
                }
            }
        }
        return f[0][0][len1];
    }
};
/*
f[i][j][k] = f[i][l][k - (l - j)] && f[i + k - (l - j)][j][l - j]
f[i][j][k] = f[i][j][l] && f[i + l][j + l][k - l]
*/