class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f[3], g[3];
        vector<int> sums(n, 0), sumk(n, 0);
        sums[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        sumk[k - 1] = sums[k - 1];
        for (int i = k; i < n; ++i) {
            sumk[i] = sums[i] - sums[i - k];
        }
        for (int i = 0; i < 3; ++i) {
            f[i] = vector<int>(n, 0);
            g[i] = vector<int>(n, -1);
        }
        
        for (int i = 0; i < 3; ++i) {
            for (int j = (i + 1) * k - 1; j < n; ++j) {
                f[i][j] = f[i][j - 1];
                g[i][j] = g[i][j - 1];
                int prev = (i == 0) ? 0 : f[i - 1][j - k];
                if (prev + sumk[j] > f[i][j]) {
                    f[i][j] = prev + sumk[j];
                    g[i][j] = j;
                }
            }
        }
        vector<int> ans;
        int i = 2, j = n - 1;
        while (i >= 0) {
            ans.push_back(g[i][j] - k + 1);
            j = g[i][j] - k;
            --i;
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};