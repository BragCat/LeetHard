class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        minStep = vector<vector<int>>(m * n, vector<int>(m * n, -1));
        int b = 0, p = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 'B') {
                    b = i * n + j;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'S') {
                    p = i * n + j;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'T') {
                    t = i * n + j;
                    grid[i][j] = '.';
                }
            }
        }
        ans = -1;
        dfs(grid, b, p, 0);
        return ans;
    }
private:
    int m, n, ans, t;
    vector<vector<int>> minStep;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >=0 && y < n;
    }
    void dfs(vector<vector<char>>& grid, int b, int p, int cnt) {
        //cout << "b:" << b << " p:" << p << " t:" << t << " ans:" << ans << " cnt:" << cnt << endl;
        //cout << "minStep[b][p]:" << minStep[b][p] << endl;
        if (ans != -1 && cnt >= ans) {
            return;
        }
        if (minStep[b][p] != -1 && cnt >= minStep[b][p]) {
            return;
        }
        minStep[b][p] = cnt;
        if (t == b) {
            ans = cnt;
            return;
        }
        int bx = b / n, by = b % n;
        int px = p / n, py = p % n;
        //cout << bx << " " << by << endl;
        //cout << px << " " << py << endl;
        for (int i = 0; i < 4; ++i) {
            int nx = px + dx[i], ny = py + dy[i];
            if (isValid(nx, ny) && grid[nx][ny] == '.') {
                if (nx != bx || ny != by) {
                    dfs(grid, b, nx * n + ny, cnt);
                } else {
                    int nbx = bx + dx[i], nby = by + dy[i];
                    if (isValid(nbx, nby) && grid[nbx][nby] == '.') {
                        dfs(grid, nbx * n + nby, nx * n + ny, cnt + 1);
                    }
                }
            }
        }
    }
};