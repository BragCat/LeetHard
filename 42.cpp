class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                ans += max(0, height[l] - height[l + 1]);
                height[l + 1] = max(height[l + 1], height[l]);
                ++l;
            } else {
                ans += max(0, height[r] - height[r - 1]);
                height[r - 1] = max(height[r - 1], height[r]);
                --r;
            }
        }
        return ans;
    }
};