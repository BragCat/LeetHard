class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> tasks;
        int n = startTime.size();
        for (int i = 0; i < n; ++i) {
            tasks.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i];
            int l = 0, r = i - 1, k = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (tasks[mid][1] <= tasks[i][0]) {
                    k = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            dp[i + 1] = max(dp[i + 1], dp[k + 1] + tasks[i][2]);
        }
        return dp[n];
    }
};