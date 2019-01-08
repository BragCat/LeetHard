class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        vector<vector<int>> f(prices.size(), vector<int>(4, MIN_INT));
        f[0][0] = -prices[0];
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(-prices[i], f[i - 1][0]);
            if (f[i - 1][0] != MIN_INT) {
                f[i][1] = max(f[i - 1][0] + prices[i], f[i - 1][1]);
            }
            if (f[i - 1][1] != MIN_INT) { 
                f[i][2] = max(f[i - 1][1] - prices[i], f[i - 1][2]);
            }
            if (f[i - 1][2] != MIN_INT) {
                f[i][3] = max(f[i - 1][2] + prices[i], f[i - 1][3]);
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            ans = max(ans, f[n - 1][i]);
        }
        return ans;
    }
private:
    const int MIN_INT = 1u << 31;
};