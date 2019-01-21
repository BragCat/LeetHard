class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numCnt;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            numCnt[nums[i]] = 0;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = getLength(numCnt, nums[i]);
            ans = max(ans, cnt);
        }
        return ans;
    }
private:
    int getLength(unordered_map<int, int> &numCnt, int num) {
        auto it = numCnt.find(num);
        if (it == numCnt.end()) {
            return 0;
        }
        if (it->second != 0) {
            return it->second;
        }
        return it->second = getLength(numCnt, num - 1) + 1;
    }
};