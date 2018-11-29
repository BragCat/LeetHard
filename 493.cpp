class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<long long> numsTotal;    
        for (auto x : nums) {
            long long twice = static_cast<long long>(x) * 2;
            numsTotal.push_back(x);
            numsTotal.push_back(twice);
        }
        sort(numsTotal.begin(), numsTotal.end());

        map<long long, int> valueLabel;
        int label = 0;
        for (int i = 0; i < numsTotal.size(); ++i) {
            if (i == 0 || numsTotal[i] != numsTotal[i - 1]) {
                valueLabel[numsTotal[i]] = ++label;
            }
        }

        treeArray = vector<int>(label + 1, 0);
        int ans = 0; 
        for (int i = 0; i < nums.size(); ++i) {
            long long twice = static_cast<long long>(nums[i]) * 2;
            ans += i - getSum(valueLabel[twice]);
            addTreeArray(valueLabel[nums[i]], 1);
        }
        return ans;
    }

private:
    vector<int> treeArray;

    int getSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += treeArray[x]; 
            x -= lowbit(x);
        } 
        return sum;
    }

    void addTreeArray(int x, int v) {
        while (x < treeArray.size()) {
            treeArray[x] += v;
            x += lowbit(x); 
        } 
    }

    int lowbit(int x) {
        return x & (-x); 
    }
};
