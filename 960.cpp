class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        for (int i = 0; i < A.size(); ++i) {
            A[i] += 'z';
        }
        int l = A[0].size();
        vector<int> f(l, l + 1);
        for (int i = 0; i < l; ++i) {
            f[i] = i;
            for (int j = 0; j < i; ++j) {
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    if (A[k][j] <= A[k][i]) {
                        ++cnt;
                    } else {
                        break;
                    }
                }
                if (cnt == n) {
                    f[i] = min(f[i], f[j] + i - j - 1);
                }
            }
        }
        return f[l - 1];
    }
};