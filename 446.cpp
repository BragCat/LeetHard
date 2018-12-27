class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<map<int, int>> seqCnt(n, map<int, int>{});
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = static_cast<long long>(A[i]) - A[j];
                if (d >= MIN_INT && d <= MAX_INT) {
                    ans += seqCnt[j][d];
                    seqCnt[i][d] += seqCnt[j][d] + 1;
                }
            }
        }
        return ans;
    }
private:
    const int MAX_INT = ~0u >> 1;
    const int MIN_INT = -MAX_INT - 1;
};