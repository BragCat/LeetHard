class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int sum = 0;
        for (auto x : A) {
            sum += x;
        }       
        int n = A.size();
        if (n == 0) {
            return false;
        }
        vector<vector<bool>> f[2] = {vector<vector<bool>>(n + 1, vector<bool>(sum + 1, false)), 
            vector<vector<bool>>(n + 1, vector<bool>(sum + 1, false))};
        f[0][0][0] = f[0][1][A[0]] = true;
        for (int i = 1; i < n; ++i) {
            f[i & 1][0][0] = true;
            for (int j = 1; j <= i + 1; ++j) {
                for (int k = 0; k <= sum; ++k) {
                    f[i & 1][j][k] = f[(i - 1) & 1][j][k];
                    if (k >= A[i]) {
                        f[i & 1][j][k] = f[i & 1][j][k] || f[(i - 1) & 1][j - 1][k - A[i]];
                    }
                }
            }            
        }
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k <= sum; ++k) {
                if (f[(n - 1) & 1][j][k] && sum * j == k * n) {
                    return true;
                }
            }
        }
        return false;
    }
};
