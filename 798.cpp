class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            A.push_back(A[i]);
        }
        map<int, int> deltaCnt;
        int ans = 0, score = 0;
        for (int i = 0; i < n; ++i) {
            ++deltaCnt[i - A[i]];
            score += (A[i] <= i);
        }
        int ansScore = score;
        for (int i = n; i < n + n; ++i) {
            score += (A[i] <= n - 1) - deltaCnt[i - n];
            if (score > ansScore) {
                ans = i - n + 1;
                ansScore = score;
            }            
            ++deltaCnt[i - A[i]];
            --deltaCnt[(i - n) - A[i - n]];
        }
        return ans;
    }
};