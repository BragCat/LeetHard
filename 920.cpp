class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long long>> f(L, vector<long long>(N, 0));
        f[0][0] = 1;
        for (int i = 1; i < L; ++i) {
            for (int j = min(K, i); j < N; ++j) {
                if (j > 0) {
                    f[i][j] = (f[i - 1][j - 1] * (j + 1)) % MODULO;
                }
                if (i >= K) {
                    f[i][j] = (f[i][j] + f[i - 1][j] * (j + 1 - K) % MODULO) % MODULO;
                } else {
                    f[i][j] = (f[i][j] + f[i - 1][j] * (j + 1 - i) % MODULO) % MODULO;
                }
            }
        }
        return f[L - 1][N - 1];
    }
private:
    const int MODULO = 1e9 + 7;
};
