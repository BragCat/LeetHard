class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int sqrtN = sqrt(2 * N), ans = 0;
        for (int i = 1; i <= sqrtN; ++i) {
            if (N * 2 % i == 0) {
                int p = i;
                int q = N * 2 / p;
                if (p % 2 == (q - 1) % 2) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};