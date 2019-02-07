class Solution {
public:
    int totalNQueens(int n) {
        BoolVector cols(n, false);
        BoolVector leftDiag(2 * n - 1, false), rightDiag(2 * n - 1, false);
        return getPlacements(0, n, cols, leftDiag, rightDiag);
    }
private:
    using BoolVector = vector<bool>;
    int getPlacements(int r, int n, BoolVector &cols, BoolVector &leftDiag, BoolVector &rightDiag) {
        if (r == n) {
            return 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            bool canOccupy = !cols[i] && !leftDiag[r + i] && !rightDiag[n - 1 + i - r];
            if (canOccupy) {
                cols[i] = leftDiag[r + i] = rightDiag[n - 1 + i - r] = true;
                ans += getPlacements(r + 1, n, cols, leftDiag, rightDiag);
                cols[i] = leftDiag[r + i] = rightDiag[n - 1 + i - r] = false;
            }
        }
        return ans;
    }
};