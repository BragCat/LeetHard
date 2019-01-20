class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<bool>> f[2];
        f[0] = f[1] = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                f[0][i][j] = true;
            }
        }
        int now = 0, next = now ^ 1;
        int ans = 1;
        while (true) {
            bool flag = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    f[next][i][j] = false;
                }
            }
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (f[now][i][j]) {
                        for (int k = 0; k < 4; ++k) {
                            int x = i + dx[k], y = j + dy[k];
                            if (x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
                                f[next][x][y] = true;
                                flag = true;
                            }
                        }
                    }
                }
            }

            if (!flag) {
                break;
            } 
            ++ans;
            now = next, next = now ^ 1;
        }
        return ans;
    }
private:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
};