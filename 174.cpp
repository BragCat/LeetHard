class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
 		int left = 1, right = MAX_INT;
 		int ans = right;
 		while (left <= right) {
 			int mid = left + (right - left) / 2;
 			if (canReachPrincess(dungeon, mid)) {
 				ans = mid;
 				right = mid - 1;
 			} else {
 				left = mid + 1;
 			}
 		}       
 		return ans;
    }
private:
	const int MAX_INT = ~0u >> 1;	
	bool canReachPrincess(vector<vector<int>> &dungeon, int initialPower) {
		int m = dungeon.size(), n = dungeon[0].size();
		vector<vector<int>> f(m, vector<int>(n, -MAX_INT));
		f[0][0] = dungeon[0][0] + initialPower;
		if (f[0][0] <= 0) {
			return false;
		}

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 && j == 0) {
					continue;
				}
				if (j > 0) {
					if (f[i][j - 1] > 0) {
						f[i][j] = max(f[i][j], f[i][j - 1] + dungeon[i][j]);
					}
				}
				if (i > 0) {
					if (f[i - 1][j] > 0) {
						f[i][j] = max(f[i][j], f[i - 1][j] + dungeon[i][j]);
					}
				}
			}
		}
		return f[m - 1][n - 1] > 0;
	}
};