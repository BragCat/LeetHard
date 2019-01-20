class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) {
            return 0;
        }
        int n = heightMap[0].size();
        if (n == 0) {
            return 0;
        }
        auto cmp = [](vector<int> &a, vector<int> &b) -> bool {return a[0] > b[0];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> h(cmp);
        vector<vector<bool>> added(m, vector<bool>(n, false));
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            h.push({heightMap[i][0], i, 0});
            h.push({heightMap[i][n - 1], i, n - 1});
            added[i][0] = added[i][n - 1] = true;
            cnt += 2 - (n - 1 == 0);
        }
        for (int i = 1; i < n - 1; ++i) {
            h.push({heightMap[0][i], 0, i});
            h.push({heightMap[m - 1][i], m - 1, i});
            added[0][i] = added[m - 1][i] = true;
            cnt += 2 - (m - 1 == 0);
        }
        
        int ans = 0;
        while (cnt < m * n) {
            auto t = h.top();
            h.pop();
            int x = t[1], y = t[2], hgt = t[0];
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !added[nx][ny]) {
                    added[nx][ny] = true;
                    ++cnt;
                    ans += max(0, hgt - heightMap[nx][ny]);
                    h.push({max(heightMap[nx][ny], hgt), nx, ny});
                }
            }
        }
        return ans;
    }
private:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
};