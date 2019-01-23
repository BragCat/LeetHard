class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = grid[0][0], r = 0;
        for (int i = 0; i < n; ++i) {
            r = max(r, *max_element(grid[i].begin(), grid[i].end()));
        }
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (existPath(grid, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
private:
    bool existPath(vector<vector<int>> &grid, int t) {
        int n = grid.size(); 
        vector<vector<bool>> searched(n, vector<bool>(n, false));
        searched[0][0] = true;
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop_front();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] <= t && !searched[nx][ny]) {
                    searched[nx][ny] = true;
                    q.push_back({nx, ny});
                }
            }
        }
        return searched[n - 1][n - 1];
    }
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
};