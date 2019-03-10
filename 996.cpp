class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        sort(A.begin(), A.end());
        vector<int> perm;
        vector<bool> used(A.size(), false);
        return getNumBySearch(perm, A, used);
    }
private:
    int getNumBySearch(vector<int> &perm, vector<int> &A, vector<bool> &used) {
        if (perm.size() == A.size()) {
            return 1;
        }
        int last = -1, ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (!used[i] && A[i] != last && (perm.empty() || isSquare(perm.back() + A[i]))) {
                perm.push_back(A[i]);
                used[i] = true;
                ans += getNumBySearch(perm, A, used);
                used[i] = false;
                perm.pop_back();
                last = A[i];
            }
        }
        return ans;
    }
    bool isSquare(int x) {
        int y = static_cast<int>(sqrt(x));
        return y * y == x;
    }
};