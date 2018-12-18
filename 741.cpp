class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
 		int m = grid.size(), n = grid[0].size();       
 		vector<vector<vector<int>>> f(m + n, vector<vector<int>>(m, vector<int>(m, MIN_INT)));
 		f[0][0][0] = grid[0][0];
 		for (int i = 1; i < m + n - 1; ++i) {
 			for (int j = max(0, i - n + 1); j <= min(m - 1, i); ++j) {
 				if (grid[j][i - j] == -1) {
 					continue;
 				}
 				for (int k = max(0, i - n + 1); k <= min(m - 1, i); ++k) {
 					if (grid[k][i - k] == -1) {
 						continue;
 					}
 					if (j > 0) {
 						if (k > 0 && f[i - 1][j - 1][k - 1] != MIN_INT) {
 							int newValue = f[i - 1][j - 1][k - 1] + grid[j][i - j] + grid[k][i - k];
 							if (j == k) {
 								newValue -= grid[k][i - k];
 							}
 							f[i][j][k] = max(f[i][j][k], newValue);
 						}
 						if (k < i && f[i - 1][j - 1][k] != MIN_INT) {
 							int newValue = f[i - 1][j - 1][k] + grid[j][i - j] + grid[k][i - k];
 							if (j == k) {
 								newValue -= grid[k][i - k];
 							}
 							f[i][j][k] = max(f[i][j][k], newValue);
 						}
 					}
 					if (j < i) {
 						if (k > 0 && f[i - 1][j][k - 1] != MIN_INT) {
 							int newValue = f[i - 1][j][k - 1] + grid[j][i - j] + grid[k][i - k];
 							if (j == k) {
 								newValue -= grid[k][i - k];
 							}
 							f[i][j][k] = max(f[i][j][k], newValue);
 						}
 						if (k < i && f[i - 1][j][k] != MIN_INT) {
 							int newValue = f[i - 1][j][k] + grid[j][i - j] + grid[k][i - k];
 							if (j == k) {
 								newValue -= grid[k][i - k];
 							}
 							f[i][j][k] = max(f[i][j][k], newValue);
 						}
 					}
 				}
 			}
 		}
 		return f[m + n - 2][m - 1][m - 1] == MIN_INT ? 0 : f[m + n - 2][m - 1][m - 1];
    }
private:
	const int MAX_INT = ~0u >> 1;
	const int MIN_INT = -MAX_INT - 1;
};