class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int lessCnt = 0, lessEqualCnt = 0;
            for (int i = 0; i < n; ++i) {
                lessCnt += count(nums, i, mid);
                lessEqualCnt += count(nums, i, mid + 1);
            } 
            if (lessCnt < k && lessEqualCnt >= k) {
                return mid;
            } else if (lessCnt >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
private:
    int count(vector<int> &nums, int index, int upperBound) {
        int left = index, right = nums.size() - 1;
        int ans = index;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] - nums[index] < upperBound) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans - index;
    }
};