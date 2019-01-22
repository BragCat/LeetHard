class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<int> sum{nums[0]};
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            sum.push_back(sum.back() + nums[i]);
        }
        vector<vector<int>> f(n, vector<int>(m, MAX_INT));
        f[0][0] = sum[0];
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= min(i, m - 1); ++j) {
                if (j == 0) {
                    f[i][j] = sum[i];
                } else {
                    for (int k = 0; k < i; ++k) {
                        f[i][j] = min(f[i][j], max(f[k][j - 1], sum[i] - sum[k]));
                    }
                }
            }
        }
        return f[n - 1][m - 1];
    }
private:
    const int MAX_INT = ~0u >> 1;
};