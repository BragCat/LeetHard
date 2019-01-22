class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int label = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> labels(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (labels[i][j] == 0 && grid[i][j] == 1) {
                    labelGrids(grid, labels, i, j, ++label);
                }
            }
        }
                
        unordered_map<int, int> labelCnt;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (labels[i][j] != 0) {
                    ++labelCnt[labels[i][j]];
                }
            }
        }
        
        int ans = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (labels[i][j] != 0) {
                    ans = max(ans, labelCnt[labels[i][j]]);
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dx[k], y = j + dy[k];
                        if (isValid(m, n, x, y) && grid[x][y] == 0) {
                            int now = 1;
                            unordered_set<int> labelSet;
                            for (int l = 0; l < 4; ++l) {
                                int nx = x + dx[l], ny = y + dy[l];
                                if (isValid(m, n, nx, ny) && labelSet.find(labels[nx][ny]) == labelSet.end()) {
                                    labelSet.insert(labels[nx][ny]);
                                    now += labelCnt[labels[nx][ny]];
                                }
                            }
                            ans = max(ans, now);
                        }
                    }
                }
            }
        }
        return ans;
    }
private:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    
    void labelGrids(vector<vector<int>> &grid, vector<vector<int>> &labels, int x, int y, int label) {
        int m = grid.size(), n = grid[0].size();
        labels[x][y] = label;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(m, n, nx, ny) && grid[nx][ny] == 1 && labels[nx][ny] == 0) {
                labelGrids(grid, labels, nx, ny, label);
            }
        }
    }

    bool isValid(int m, int n, int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
};