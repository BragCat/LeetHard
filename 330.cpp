class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long r = 1;
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > r && r <= n) {
                ++ans;
                r += r;
            }
            if (r > n) {
                return ans;
            }
            r += nums[i];
        }
        while (r <= n) {
            ++ans;
            r += r;
        }
        return ans;
    }
};