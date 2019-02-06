class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        vector<vector<string>> ans;
        BoolVector cols(n, false);
        BoolVector leftDiag(2 * n - 1, false), rightDiag(2 * n - 1, false);
        getPlacements(0, n, board, cols, leftDiag, rightDiag, ans);
        return ans;
    }
private:
    using BoolVector = vector<bool>;
    void getPlacements(int r, int n, vector<string> &board, BoolVector &cols, BoolVector &leftDiag, BoolVector &rightDiag, vector<vector<string>> &ans) {
        if (r == n) {
            ans.push_back(board);
            return;
        }
        string rs(n, '.');
        for (int i = 0; i < n; ++i) {
            bool canOccupy = !cols[i] && !leftDiag[r + i] && !rightDiag[n - 1 + i - r];
            if (canOccupy) {
                cols[i] = leftDiag[r + i] = rightDiag[n - 1 + i - r] = true;
                rs[i] = 'Q';
                board.push_back(rs);
                getPlacements(r + 1, n, board, cols, leftDiag, rightDiag, ans);
                board.pop_back();
                rs[i] = '.';
                cols[i] = leftDiag[r + i] = rightDiag[n - 1 + i - r] = false;
            }
        }
    }
};