class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> num_cnt;
        map<int, int> cnt_cnt;
        int num = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            int t = ++num_cnt[nums[i]];
            if (t == 1) {
                ++num;
            } else {
                --cnt_cnt[t - 1];
                if (cnt_cnt[t - 1] == 0) {
                    cnt_cnt.erase(t - 1);
                }
            }
            ++cnt_cnt[t];
            if (cnt_cnt.size() == 1) {
                auto b = cnt_cnt.begin();
                if (b->first == 1 || b->second == 1) {
                    ans = i + 1;
                }
            } else if (cnt_cnt.size() == 2) {
                auto b = cnt_cnt.begin();
                auto e = b;
                ++e;
                if (b->first + 1 == e->first && e->second == 1 || b->first == 1 && b->second == 1) {
                    ans = i + 1;
                }
            }
        }
        return ans;
    }
private:
    const int MAX_INT = ~0u >> 1;
};