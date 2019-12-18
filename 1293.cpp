class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        to = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        dfs(grid, k, 0, 0, 0);
        return to[0][0][k] == MAX_INT ? -1 : to[0][0][k];
    }
private:
    const int MAX_INT = ~0u >> 1;
    int m, n;
    vector<vector<vector<int>>> to;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    
    void dfs(vector<vector<int>>& grid, int k, int x, int y, int step) {
        if (x == m - 1 && y == n - 1) {
            to[x][y][k] = 0;
        }
        if (to[x][y][k] != -1) {
            return;
        }
        to[x][y][k] = MAX_INT;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (grid[nx][ny] == 0) {
                    dfs(grid, k, nx, ny, step + 1);
                    if (to[nx][ny][k] != MAX_INT) {
                        to[x][y][k] = min(to[x][y][k], to[nx][ny][k] + 1);
                    }
                } else if (k > 0) {
                    dfs(grid, k - 1, nx, ny, step + 1);
                    if (to[nx][ny][k - 1] != MAX_INT) {
                        to[x][y][k] = min(to[x][y][k], to[nx][ny][k - 1] + 1);
                    }
                }
            }
        }
    }
};