class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) {
            return 0;
        }
        vector<LL> sums{nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            sums.push_back(sums[i - 1] + nums[i]);
        }
        vector<LL> sumNums{0};
        for (int i = 0; i < sums.size(); ++i) {
            sumNums.push_back(sums[i]);
            sumNums.push_back(sums[i] - lower);
            sumNums.push_back(sums[i] - upper);
        }
        sort(sumNums.begin(), sumNums.end());
        
        unordered_map<LL, int> sum2Label;
        int cnt = 0;
        for (int i = 0; i < sumNums.size(); ++i) {
            if (i == 0 || sumNums[i] != sumNums[i - 1]) {
                sum2Label[sumNums[i]] = ++cnt;
            }
        }
        vector<int> fenwick(cnt + 1, 0);
        int ans = 0;
        insertFenwick(fenwick, sum2Label[0]);
        for (int i = 0; i < sums.size(); ++i) {
            int lowLabel = sum2Label[sums[i] - upper] - 1;
            int uppLabel = sum2Label[sums[i] - lower];
            ans += getFenwickSum(fenwick, uppLabel) - getFenwickSum(fenwick, lowLabel);
            insertFenwick(fenwick, sum2Label[sums[i]]);
        }
        return ans;
    }
private:
    using LL = long long;
    int getFenwickSum(vector<int> &fenwick, int label) {
        int sum = 0;
        while (label > 0) {
            sum += fenwick[label];
            label -= lowbit(label);
        }
        return sum;
    }
    
    void insertFenwick(vector<int> &fenwick, int label) {
        while (label < fenwick.size()) {
            ++fenwick[label];
            label += lowbit(label);
        }
    }
    
    int lowbit(int x) {
        return x & (-x);
    }
};
