class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int stx = -1, sty = -1, cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    stx = i, sty = j;
                } else {
                    cnt += (grid[i][j] >= 0);
                }
            }
        }
        return getAnsDFS(stx, sty, 0, cnt, grid);
    }
private:
    int getAnsDFS(int x, int y, int cnt, int target, vector<vector<int>> &grid) {
        if (grid[x][y] == 2) {
            return cnt == target;
        }
        
        int m = grid.size(), n = grid[0].size(), origin = grid[x][y];
        grid[x][y] = -2;
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] >= 0) {
                ans += getAnsDFS(nx, ny, cnt + 1, target, grid);
            }
        }
        
        grid[x][y] = origin;
        return ans;
    }
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
};