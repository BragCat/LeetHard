class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty()) {
            return {};
        }
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            addToQueue(q, i, nums);
        }
        vector<int> ans{nums[q.front()]};
        for (int i = k; i < nums.size(); ++i) {
            popFromQueue(q, i - k + 1, nums);
            addToQueue(q, i, nums);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
private:
    void addToQueue(deque<int> &q, int index, vector<int> &nums) {
        while (!q.empty() && nums[q.back()] <= nums[index]) {
            q.pop_back();
        }
        q.push_back(index);
    }
    void popFromQueue(deque<int> &q, int index, vector<int> &nums) {
        while (!q.empty() && q.front() < index) {
            q.pop_front();
        }
    }
};