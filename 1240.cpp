class Solution {
public:
    int tilingRectangle(int n, int m) {
        r = n, c = m;
        board = vector<vector<int>>(r, vector<int>(c));
        ans = ~0u >> 1;
        dfs(0, r * c, min(r, c));
        return ans;
    }
private:
    vector<vector<int>> board;
    int ans, r, c;
    
    void dfs(int cnt, int rest, int d) {
        if (cnt >= ans) {
            return;
        }
        if (rest == 0) {
            ans = cnt;
            return;
        }
        if (d == 0 || cnt + round(rest / (d * d)) >= ans) {
            return;
        }
        for (int i = 0; i <= r - d; ++i) {
            for (int j = 0; j <= c - d; ++j) {
                if (board[i][j] == 0) {
                    bool valid = true;
                    for (int ii = i; ii < i + d; ++ii) {
                        for (int jj = j; jj < j + d; ++jj) {
                            if (board[ii][jj] != 0) {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) {
                            break;
                        }
                    }
                    if (!valid) {
                        continue;
                    }
                    fill_with(i, j, d, 1);
                    dfs(cnt + 1, rest - d * d, d);
                    fill_with(i, j, d, 0);
                }
            }
        }
        dfs(cnt, rest, d - 1);
    }
    void fill_with(int i, int j, int d, int x) {
        for (int ii = i; ii < i + d; ++ii) {
            for (int jj = j; jj < j + d; ++jj) {
                board[ii][jj] = x;
            }
        }
    }
};