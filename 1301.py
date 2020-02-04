class Solution:
    MODULO = int(1e9 + 7)
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:
        m, n = len(board), len(board[0])
        dp = [[[-1, 0] for _ in range(n)] for _ in range(m)]
        dp[m - 1][n - 1] = [0, 1]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if board[i][j] != 'X':
                    v = 0 if i == 0 and j == 0 or i == m - 1 and j == n - 1 else int(board[i][j])
                    if i != m - 1 and dp[i + 1][j][0] != -1:
                        if dp[i][j][0] < dp[i + 1][j][0]:
                            dp[i][j][0], dp[i][j][1] = dp[i + 1][j][0], dp[i + 1][j][1]
                        elif dp[i][j][0] == dp[i + 1][j][0]:
                            dp[i][j][1] += dp[i + 1][j][1]
                    if j != n - 1 and dp[i][j + 1][0] != -1:
                        if dp[i][j][0] < dp[i][j + 1][0]:
                            dp[i][j][0], dp[i][j][1] = dp[i][j + 1][0], dp[i][j + 1][1]
                        elif dp[i][j][0] == dp[i][j + 1][0]:
                            dp[i][j][1] += dp[i][j + 1][1]
                    if i != m - 1 and j != n - 1 and dp[i + 1][j + 1][0] != -1:
                        if dp[i][j][0] < dp[i + 1][j + 1][0]:
                            dp[i][j][0], dp[i][j][1] = dp[i + 1][j + 1][0], dp[i + 1][j + 1][1]
                        elif dp[i][j][0] == dp[i + 1][j + 1][0]:
                            dp[i][j][1] += dp[i + 1][j + 1][1]
                    if dp[i][j][0] != -1:
                        dp[i][j][0] += v
                        dp[i][j][1] %= self.MODULO
        if dp[0][0][0] == -1:
            dp[0][0][0] = 0
        return dp[0][0]
            
                    