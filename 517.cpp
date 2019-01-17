class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int tot = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (tot % n != 0) {
            return -1;
        }
        int ans = 0, toLeft = 0;
        for (int i = 0; i < n; ++i) {
            int toRight = machines[i] - toLeft - tot / n;
            ans = max(ans, max(toLeft, max(toRight, toLeft + toRight)));
            toLeft = -toRight;
        }
        return ans;
    }
};