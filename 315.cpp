class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<pair<int, int>> numIndex;
        for (int i = 0; i < n; ++i) {
            numIndex.emplace_back(nums[i], i);
        }
        sort(numIndex.begin(), numIndex.end(), [](auto &a, auto &b) -> bool {return a.first < b.first;});
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || numIndex[i].first != numIndex[i - 1].first) {
                ++cnt;
            }
            nums[numIndex[i].second] = cnt;
        }
        
        vector<int> fenwickTree(cnt + 1, 0);
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans.push_back(getSumFromFenwick(fenwickTree, nums[i] - 1));
            addNumToFenwick(fenwickTree, nums[i]);
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
private:
    int getSumFromFenwick(vector<int> &fenwick, int x) {
        int ans = 0;
        while (x > 0) {
            ans += fenwick[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void addNumToFenwick(vector<int> &fenwick, int x) {
        while (x < fenwick.size()) {
            ++fenwick[x];
            x += lowbit(x);
        }
    }
    int lowbit(int x) {
        return x & (-x);
    }
};