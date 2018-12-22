class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int ans = 0, c = 0;
        vector<int> candy(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0 || ratings[i - 1] >= ratings[i]) {
                candy[i] = 1;
            } else {
                candy[i] = candy[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1 || ratings[i] <= ratings[i + 1]) {
                candy[i] = max(candy[i], 1);
            } else {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }
        for (int c : candy) {
            ans += c;
        }
        return ans;
    }
};