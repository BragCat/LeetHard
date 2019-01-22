class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.length();
        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
        for (int j = 0; j <= n; ++j) {
            f[0][j] = 1;
        }
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            if (S[i] == 'I') {
                for (int j = 0; j < n - i; ++j) {
                    f[i + 1][j] = sum = (sum + f[i][j]) % MODULO;
                }
            } else {
                for (int j = n - i - 1; j >= 0; --j) {
                    f[i + 1][j] = sum = (sum + f[i][j + 1]) % MODULO;
                }
            }
        }
        return f[n][0];
    }
private:
    const int MODULO = 1e9 + 7;
};