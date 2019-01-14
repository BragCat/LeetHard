class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = MIN_INT;
        int m = matrix.size();
        if (m == 0) {
            return ans;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return ans;
        }
        for (int i = 0; i < n; ++i) {
            vector<int> sums(m, 0);
            for (int j = i; j < n; ++j) {
                for (int l = 0; l < m; ++l) {
                    sums[l] += matrix[l][j];
                } 
                ans = max(ans, maxSumSubArray(sums, k));
            }
        }
        return ans;
    }
private:
    const int MAX_INT = ~0u >> 1;
    const int MIN_INT = -MAX_INT - 1;
    int maxSumSubArray(vector<int> a, int k) {
        if (a.size() == 0) {
            return MIN_INT;
        }
        int n = a.size(), mid = n / 2;
        vector<int> lsum{a[mid]}, rsum{0};
        for (int i = mid - 1; i >= 0; --i) {
            lsum.push_back(lsum.back() + a[i]);
        }
        for (int i = mid + 1; i < n; ++i) {
            rsum.push_back(rsum.back() + a[i]);
        }
        sort(lsum.begin(), lsum.end());
        sort(rsum.begin(), rsum.end());
        int ans = MIN_INT, l = 0, r = rsum.size() - 1;
        while (l < lsum.size() && r >= 0) {
            while (r >= 0 && lsum[l] + rsum[r] > k) {
                --r;
            }
            while (l < lsum.size() && lsum[l] + rsum[r] <= k) {
                ans = max(ans, lsum[l] + rsum[r]);
                ++l;
            }
        }
        ans = max(ans, maxSumSubArray(vector<int>(a.begin(), a.begin() + mid), k));
        ans = max(ans, maxSumSubArray(vector<int>(a.begin() + mid + 1, a.end()), k));
        return ans;
    }
};