class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int ans = A.size() + 1, sum = 0;
        deque<pair<int, int>> sumIndex;
        sumIndex.emplace_back(0, -1);
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i]; 
            while (!sumIndex.empty()) {
                if (sum - sumIndex.front().first >= K) {
                    ans = min(ans, i - sumIndex.front().second);
                    sumIndex.pop_front();
                } else {
                    break; 
                }
            }
            while (!sumIndex.empty() && sum <= sumIndex.back().first) {
                sumIndex.pop_back(); 
            }
            sumIndex.emplace_back(sum, i);
        }
        return (ans == A.size() + 1) ? -1 : ans;
    }
};
