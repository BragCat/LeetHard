class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, MAX_INT);
        f[0] = 0;
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i < n; ++i) {
            while (!q.empty() && q.front() + nums[q.front()] < i) {
                q.pop_front();
            }
            if (!q.empty()) {
                f[i] = f[q.front()] + 1;
            }
            while (!q.empty() && f[q.back()] == f[i] && q.back() + nums[q.back()] <= i + nums[i]) {
                q.pop_back();
            }
            if (q.empty() || q.back() + nums[q.back()] < i + nums[i]) {
                q.push_back(i);
            }
        }
        return f[n - 1];
    }
private:
    const int MAX_INT = ~0u >> 1;
};