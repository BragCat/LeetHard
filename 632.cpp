class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int minNum = MAX_INT, maxNum = MIN_INT;
        auto cmp = [](const vector<int> &a, const vector<int> &b) -> bool {return a[0] > b[0];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> h(cmp);
        for (int i = 0; i < nums.size(); ++i) {
            h.push({nums[i][0], i, 0});
            minNum = min(minNum, nums[i][0]);
            maxNum = max(maxNum, nums[i][0]);
        }
        int ansMin = minNum, ansMax = maxNum;
        while (true) {
            auto &t = h.top();
            int minV = t[0], minL = t[1], minI = t[2];
            if (minI == nums[minL].size() - 1) {
                break;
            }
            h.pop();
            h.push({nums[minL][minI + 1], minL, minI + 1});
            maxNum = max(maxNum, nums[minL][minI + 1]);
            minNum = h.top()[0];
            if (maxNum - minNum < ansMax - ansMin) {
                ansMax = maxNum, ansMin = minNum;
            }
        }
        return {ansMin, ansMax};
    }
private:
    const int MAX_INT = ~0u >> 1;
    const int MIN_INT = -MAX_INT - 1;
};