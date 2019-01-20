class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();
        if (n == 0) {
            return 0;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[0][0] ^ board[i][0] ^ board[i][j] ^ board[0][j] == 1) {
                    return -1;
                }
            }
        }
        
        int rowCnt = 0, colCnt = 0;
        int rowSwap = 0, colSwap = 0;
        for (int i = 0; i < n; ++i) {
            rowCnt += board[0][i];
            rowSwap += (board[i][0] == i % 2);
            colCnt += board[i][0];
            colSwap += (board[0][i] == i % 2);
        }
        if (rowCnt < n / 2 || rowCnt > (n + 1) / 2 || colCnt < n / 2 || colCnt > (n + 1) / 2) {
            return -1;
        }
        
        if (n % 2 == 0) {
            rowSwap = min(rowSwap, n - rowSwap);
            colSwap = min(colSwap, n - colSwap);
        } else {
            if (rowSwap % 2 == 1) {
                rowSwap = n - rowSwap;
            }
            if (colSwap % 2 == 1) {
                colSwap = n - colSwap;
            }
        }
        return (rowSwap + colSwap) / 2;
    }
};