class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows, cols, boxes;
        rows = cols = boxes = vector<vector<bool>>(N, vector<bool>(N, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (board[i][j] != '.') {
                    int v = board[i][j] - '1';
                    rows[i][v] = cols[j][v] = boxes[i / 3 * 3 + j / 3][v] = true;
                }
            }
        }
        fillSudoku(0, 0, board, rows, cols, boxes);
    }
private:
    const int N = 9;
    using State = vector<vector<bool>>;
    bool fillSudoku(int r, int c, vector<vector<char>> &board, State &rows, State &cols, State &boxes) {
        if (r == N) {
            return true;
        }
        int nr = r, nc = c + 1;
        if (nc == N) {
            ++nr;
            nc = 0;
        }
        if (board[r][c] != '.') {
            return fillSudoku(nr, nc, board, rows, cols, boxes);
        } else {
            for (int i = 0; i < 9; ++i) {
                int b = r / 3 * 3 + c / 3;
                if (!rows[r][i] && !cols[c][i] && !boxes[b][i]) {
                    rows[r][i] = cols[c][i] = boxes[b][i] = true;
                    board[r][c] = static_cast<char>(i + '1');
                    bool res = fillSudoku(nr, nc, board, rows, cols, boxes);
                    if (res) {
                        return true;
                    }
                    board[r][c] = '.';
                    rows[r][i] = cols[c][i] = boxes[b][i] = false;
                }
            }
            return false;
        }
    }
};