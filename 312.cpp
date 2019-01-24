class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> f(n, vector<int>(n, 0));
        for (int l = 2; l < n; ++l) {
            for (int i = 0; i < n - l; ++i) {
                int j = i + l;
                for (int k = i + 1; k < j; ++k) {
                    f[i][j] = max(f[i][j], f[i][k] + f[k][j] + nums[i] * nums[k] * nums[j]);
                }
            }
        }
        return f[0][n - 1];
    }
};