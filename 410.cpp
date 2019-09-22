class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        LL l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0L);
        LL ans = -1;
        while (l <= r) {
            LL mid = (l + r) / 2;
            if (check(nums, mid, m)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
private:
    using LL = long long;
    bool check(vector<int>& nums, LL bound, int m) {
        int cnt = 1;
        LL sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = sum + nums[i];
            if (sum > bound) {
                ++cnt;
                sum = nums[i];
            }
        }
        return cnt <= m;
    }
};