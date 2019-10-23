struct State {
    int x, y, dir;
    State(int x, int y, int dir): x(x), y(y), dir(dir) {}
};
const int dx[2] = {0, 1};
const int dy[2] = {1, 0};
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<State> q{State(0, 0, 0)};
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(2, false)));
        visited[0][0][0] = true;
        int step = 0;
        while (!q.empty()) {
            vector<State> nq;
            for (int i = 0; i < q.size(); ++i) {
                int x1 = q[i].x, y1 = q[i].y, dir = q[i].dir;
                int x2 = x1 + dx[dir], y2 = y1 + dy[dir];
                if (x1 == m - 1 && x2 == m - 1 && y1 == n - 2 && y2 == n - 1) {
                    return step;
                }
                for (int j = 0; j < 2; ++j) {
                    int nx1 = x1 + dx[j], ny1 = y1 + dy[j];
                    int nx2 = x2 + dx[j], ny2 = y2 + dy[j];
                    if (nx1 < m && ny1 < n && nx2 < m && ny2 < n && grid[nx1][ny1] == 0 && grid[nx2][ny2] == 0 && !visited[nx1][ny1][dir]) {
                        nq.emplace_back(nx1, ny1, dir);
                        visited[nx1][ny1][dir] = true;
                    } 
                }
                if (dir == 0) {
                    int nx1 = x1, ny1 = y1, nx2 = x1 + 1, ny2 = y1;
                    if (nx1 < m && ny1 < n && nx2 < m && ny2 < n && grid[nx2][ny2] == 0 && grid[nx2][ny2 + 1] == 0 && !visited[nx1][ny1][1]) {
                        nq.emplace_back(nx1, ny1, 1);
                        visited[nx1][ny1][1] = true;
                    }
                }
                if (dir == 1) {
                    int nx1 = x1, ny1 = y1, nx2 = x1, ny2 = y1 + 1;
                    if (nx1 < m && ny1 < n && nx2 < m && ny2 < n && grid[nx2][ny2] == 0 && grid[nx2 + 1][ny2] == 0 && !visited[nx1][ny1][0]) {
                        nq.emplace_back(nx1, ny1, 0);
                        visited[nx1][ny1][0] = true;
                    }
                }
            }
            q.swap(nq);
            ++step;
        }
        return -1;
    }
};