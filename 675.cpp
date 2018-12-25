class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, pair<int, int>>> trees{{0, {0, 0}}};
        int m = forest.size(), n = forest[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (forest[i][j] > 0) {
                    trees.emplace_back(forest[i][j], make_pair(i, j));
                }
            }
        }
        sort(trees.begin(), trees.end());
        
        int ans = 0;
        for (int t = 0; t < trees.size() - 1; ++t) {
            int x = trees[t].second.first, y = trees[t].second.second;
            if (x == trees[t + 1].second.first && y == trees[t + 1].second.second) {
                continue;
            }
            vector<vector<bool>> searched(m, vector<bool>(n, false));
            vector<vector<int>> steps(m, vector<int>(n, 0));
            searched[x][y] = true;
            steps[x][y] = 0;
            deque<pair<int, int>> q;
            q.emplace_back(x, y);
            bool find = false;
            while (!q.empty()) {
                int x = q.front().first, y = q.front().second;
                q.pop_front();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !searched[nx][ny] && forest[nx][ny] != 0) {
                        if (nx == trees[t + 1].second.first && ny == trees[t + 1].second.second) {
                            ans += steps[x][y] + 1;
                            find = true;
                            break;
                        }
                        searched[nx][ny] = true;
                        steps[nx][ny] = steps[x][y] + 1;
                        q.emplace_back(nx, ny);
                    }
                }
                if (find) {
                    break;
                }
            }
            if (!find) {
                return -1;
            }
        }
        return ans;
    }
private:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
};