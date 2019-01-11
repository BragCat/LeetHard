class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        vector<int> f(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(A[i], A[j])) {
                    unionSet(f, i, j);
                }
            }
        }
        int ans = 0;
        vector<bool> counted(n, false);
        for (int i = 0; i < n; ++i) {
            int r = getRoot(f, i);
            if (!counted[r]) {
                ++ans;
                counted[r] = true;
            }
        }
        return ans;
    }
private:
    bool isSimilar(const string &a, const string &b) {
        if (a.length() != b.length()) {
            return false;
        }
        int len = a.length(), first = 0, second = 0, cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                if (cnt == 0) {
                    first = i;
                    ++cnt;
                } else if (cnt == 1) {
                    second = i;
                    ++cnt;
                } else {
                    return false;
                }
            }
        }
        return (cnt == 0 || (cnt == 2 && a[first] == b[second] && a[second] == b[first]));
    }
    
    void unionSet(vector<int> &f, int a, int b) {
        int ra = getRoot(f, a);
        int rb = getRoot(f, b);
        if (ra != rb) {
            f[ra] = rb;
        }
    }
    
    int getRoot(vector<int> &f, int a) {
        if (f[a] == -1) {
            return a;
        }
        f[a] = getRoot(f, f[a]);
        return f[a];
    }
};