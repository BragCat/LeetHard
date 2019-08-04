class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        vector<int> f(n, 0);
        dp(f, text, 0, n - 1);
        return f[0];
    }
private:
    void dp(vector<int>& f, string& text, int l, int r) {
        if (f[l] != 0) {
            return;
        }
        if (l > r) {
            return;
        }
        int mid = l + (r - l + 1) / 2;
        for (int i = l + 1; i <= mid; ++i) {
            if (text.substr(l, i - l) == text.substr(r - (i - l) + 1, i - l)) {
                dp(f, text, i, r - (i - l));
                f[l] = max(f[l], f[i] + 2);
            }
        }
        if (f[l] == 0) {
            f[l] = 1;
        }
    }
};