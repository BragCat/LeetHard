class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> f(len1 + 1, vector<int>(len2 + 1, MAX_INT));
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                if (i == 0 || j == 0) {
                    f[i][j] = max(i, j);
                } else {
                    f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
                }
            }
        }
        return f[len1][len2];
    }
private:
    const int MAX_INT = ~0u >> 1;
};