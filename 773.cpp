class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, int> reached;
        int start = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                start = start * 10 + board[i][j];
            }
        }
        
        if (start == TARGET) {
            return 0;
        }
        reached[start] = 0;
        deque<int> q{start};
        while (!q.empty()) {
            int s = q.front();
            q.pop_front();
            int step = reached[s];
            vector<vector<int>> now(M, vector<int>(N, 0));
            for (int i = M - 1; i >= 0; --i) {
                for (int j = N - 1; j >= 0; --j) {
                    now[i][j] = s % 10;
                    s /= 10;
                }
            }
            int x = -1, y = -1;
            for (int i = 0; i < M; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (now[i][j] == 0) {
                        x = i, y = j;
                        break;
                    }
                }
            }
            
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                    decltype(now) next(now);
                    swap(next[x][y], next[nx][ny]);
                    int ns = 0;
                    for (int i = 0; i < M; ++i) {
                        for (int j = 0; j < N; ++j) {
                            ns = ns * 10 + next[i][j];
                        }
                    }
                    if (reached.find(ns) == reached.end()) {
                        if (ns == TARGET) {
                            return step + 1;
                        }
                        reached[ns] = step + 1;
                        q.push_back(ns);
                    }
                }
            }
        }
        return -1;
    }
private:
    const int M = 2;
    const int N = 3;
    const int TARGET = 123450;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
};