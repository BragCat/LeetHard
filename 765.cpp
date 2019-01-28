class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[row[i]] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            int x = row[i], y = x ^ 1;
            int j = pos[y];
            if (i + 1 != j) {
                swap(row[i + 1], row[j]);
                swap(pos[row[i + 1]], pos[row[j]]);
                ++ans;
            }
        }
        return ans;
    }
};