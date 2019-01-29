class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        vector<int> f(1 << 16, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = A[i] & A[j];
                if (f[a] == -1) {
                    f[a] = 0;
                    for (int k = 0; k < n; ++k) {
                        if ((a & A[k]) == 0) {
                            ++f[a];
                        }
                    }
                }
                ans += f[a];
            }
        }
        return ans;
    }
};