class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<VV> f(n, VV(n, vector<int>(n, 0)));
        return getAns(0, n - 1, 0, boxes, f);
    }
private:
    using VV = vector<vector<int>>;
    int getAns(int l, int r, int k, vector<int> &boxes, vector<VV> &f) {
        if (l > r) {
            return 0;
        }
        while (l <= r && boxes[r - 1] == boxes[r]) {
            --r, ++k;
        }
        if (f[l][r][k] != 0) {
            return f[l][r][k];
        }
        
        f[l][r][k] = getAns(l, r - 1, 0, boxes, f) + (k + 1) * (k + 1);
        for (int i = l; i < r; ++i) {
            if (boxes[i] == boxes[r]) {
                f[l][r][k] = max(f[l][r][k], getAns(l, i, k + 1, boxes, f) + getAns(i + 1, r - 1, 0, boxes, f));
            }
        }
        return f[l][r][k];
    }
};