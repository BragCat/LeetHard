class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        auto cmp = [](pair<int, int> &a, pair<int, int> &b) -> bool {return a.first * b.second > a.second * b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                q.emplace(A[i], A[j]);
            }
        }
        --K;
        while (K-- > 0) {
            q.pop();
        }
        return vector<int>{q.top().first, q.top().second};
    }
};