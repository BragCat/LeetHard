class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        int avgGap = (maxNum - minNum + 1) / n + 1;
        vector<int> minInGap(n, MAX_INT);
        vector<int> maxInGap(n, MIN_INT);
        for (auto num : nums) {
            int index = (num - minNum) / avgGap;
            minInGap[index] = min(minInGap[index], num);
            maxInGap[index] = max(maxInGap[index], num);
        }
        int ans = 0;
        int prevNum = -1;
        for (int i = 0; i < n; ++i) {
            if (minInGap[i] != MAX_INT) {
                if (prevNum != -1) {
                    ans = max(ans, minInGap[i] - prevNum);
                }
                prevNum = maxInGap[i];
            }
        }
        return ans;
    }
private:
    const int MAX_INT = ~0u >> 1;
    const int MIN_INT = -MAX_INT - 1;
};