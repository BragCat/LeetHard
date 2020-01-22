class Solution:
    MAX_INT = 1 << 31
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        n = len(arr)
        dp = [[self.MAX_INT] * n for _ in range(n)]
        min0, min1 = (0, -1), (0, -1)
        for i in range(n):
            new_min0, new_min1 = (self.MAX_INT, -1), (self.MAX_INT, -1)
            for j in range(n):
                if min0[1] != j:
                    dp[i][j] = min0[0] + arr[i][j]
                else:
                    dp[i][j] = min1[0] + arr[i][j]
                if dp[i][j] < new_min0[0]:
                    new_min0, new_min1 = (dp[i][j], j), new_min0
                elif dp[i][j] < new_min1[0]:
                    new_min1 = (dp[i][j], j)
            min0, min1 = new_min0, new_min1
        return min0[0]