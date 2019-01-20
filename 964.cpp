class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int plus = 0, minus = 0, k = 0;
        while (target > 0) {
            int remainder = target % x;
            target /= x;
            if (k == 0) {
                plus = remainder * 2;
                minus = (x - remainder) * 2;
            } else {
                int tempPlus = min(remainder * k + plus, (remainder + 1) * k + minus);
                int tempMinus = min((x - remainder) * k + plus, (x - remainder - 1) * k + minus);
                plus = tempPlus, minus = tempMinus;
            }
            ++k;
        }
        return min(plus, k + minus) - 1;
    }
};