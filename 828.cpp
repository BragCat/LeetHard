class Solution {
public:
    int uniqueLetterString(string S) {
        int n = S.length();
        if (n == 0) {
            return 0;
        }
        vector<long long> left(n, 0), right(n, 0);
        vector<int> last(26, -1);
        for (int i = 0; i < n; ++i) {
            left[i] = i - last[S[i] - 'A'];
            last[S[i] - 'A'] = i;
        }
        last = vector<int>(26, n);
        for (int i = n - 1; i >= 0; --i) {
            right[i] = last[S[i] - 'A'] - i;
            last[S[i] - 'A'] = i;
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = (ans + left[i] * right[i] % MODULO) % MODULO; 
        }
        return ans;
    }
private:
    const int MODULO = 1e9 + 7;
};