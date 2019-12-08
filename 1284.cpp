class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        ans = -1;
        dfs(mat, 0, 0, 0);
        return ans;
    } 
private:
    int m, n;
    int ans;
    void dfs(vector<vector<int>>& mat, int x, int y, int t) {
        if (ans != -1 && t >= ans) {
            return;
        }
        if (x == m) {
            if (check(mat)) {
                ans = t;
            }
            return;
        }
        int nx = x, ny = y + 1;
        if (ny == n) {
            ++nx, ny = 0;
        }
        dfs(mat, nx, ny, t);
        update(mat, x, y, 1);
        dfs(mat, nx, ny, t + 1);
        update(mat, x, y, -1);
    }
    void update(vector<vector<int>>& cnt, int x, int y, int d) {
        cnt[x][y] += d;
        if (x > 0) {
            cnt[x - 1][y] += d;
        }
        if (y > 0) {
            cnt[x][y - 1] += d;
        }
        if (x < m - 1) {
            cnt[x + 1][y] += d;
        }
        if (y < n - 1) {
            cnt[x][y + 1] += d;
        }
    }
    bool check(vector<vector<int>>& mat) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //cout << mat[i][j] << " ";
                if (mat[i][j] % 2 != 0) {
                    return false;
                }
            }
            //cout << endl;
        }
        return true;
    }
};