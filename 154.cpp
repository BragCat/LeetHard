class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return MAX_INT;
        }
        return getMinFromRange(nums, 0, n - 1);
    }
private:
    int getMinFromRange(vector<int> &nums, int l, int r) {
        if (l > r) {
            return MAX_INT;
        }
        if (l == r || nums[l] < nums[r]) {
            return nums[l];
        }
        int mid = l + (r - l) / 2;
        if (nums[mid] > nums[l]) {
            return getMinFromRange(nums, mid + 1, r);
        } else if (nums[mid] < nums[r]) {
            return getMinFromRange(nums, l, mid);
        } else {
            return min(getMinFromRange(nums, l, mid), getMinFromRange(nums, mid + 1, r));
        }
    }
    const int MAX_INT = ~0u >> 1;
};