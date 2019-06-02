class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> colSum(m, vector<int>(n, 0)); 
        for (int i = 0; i < n; ++i) {
            colSum[0][i] = matrix[0][i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                colSum[i][j] = colSum[i - 1][j] + matrix[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                vector<int> sum;
                for (int k = 0; k < n; ++k) {
                    sum.push_back(colSum[j][k] - (i == 0 ? 0 : colSum[i - 1][k]));
                }         
                unordered_map<int, int> cnt;
                int tot = 0;
                ++cnt[0];
                for (int k = 0; k < n; ++k) {
                    tot += sum[k];
                    ans += cnt[tot - target];
                    ++cnt[tot];
                }
            }
        }
        return ans;
    }
};