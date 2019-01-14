class QueueState {
public:
    int step, row, col, keyState;
    QueueState(int step, int row, int col, int keyState): step(step), row(row), col(col), keyState(keyState) {}
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> searched(m * n, vector<bool>(1 << 6, false));
        int finalKeyState = 0, stRow = -1, stCol = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '@') {
                    stRow = i, stCol = j;
                } else if (islower(grid[i][j])) {
                    finalKeyState = finalKeyState | (1 << (grid[i][j] - 'a'));
                }
            }
        }
        queue<QueueState> q;
        q.push(QueueState(0, stRow, stCol, 0));
        searched[stRow * n + stCol][0] = true;
        while (!q.empty()) {
            auto e = q.front();
            q.pop();
            int s = e.step, r = e.row, c = e.col, ks = e.keyState;
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (grid[nr][nc] != '#' && (!isupper(grid[nr][nc]) || ((ks & (1 << (grid[nr][nc] - 'A'))) != 0))) {
                        int nks = ks;
                        if (islower(grid[nr][nc])) {
                            nks = nks | (1 << (grid[nr][nc] - 'a'));
                        }
                        if (!searched[nr * n + nc][nks]) {
                            if (nks == finalKeyState) {
                                return s + 1;
                            }
                            searched[nr * n + nc][nks] = true;
                            q.push(QueueState(s + 1, nr, nc, nks));
                        }
                    }
                }
            }
        }
        return -1;
    }
private:
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};
};