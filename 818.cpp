class Solution {
public:
    int racecar(int target) {
        if (f[target] != -1) {
            return f[target];
        }
        if (target == 0) {
            f[target] = 0;
        } else {
            int n = floor(log2(target)) + 1;
            if (exp2(n) - 1 == target) {
                f[target] = n;
            } else {
                f[target] = racecar(exp2(n) - 1 - target) + n + 1;
                for (int i = 0; i < n - 1; ++i) {
                    f[target] = min(f[target], racecar(target - exp2(n - 1) + exp2(i)) + n + i + 1);
                }
            }
        }
        return f[target];
    }
private:
    vector<int> f = vector<int>(10001, -1);
};