class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> pcs;
        for (int i = 0; i < n; ++i) {
            pcs.emplace_back(Profits[i], Capital[i]);
        }
        sort(pcs.begin(), pcs.end(), [](auto &a, auto &b) -> bool {return a.second < b.second;});
        priority_queue<int> gains;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (pcs[i].second <= W) {
                gains.push(pcs[i].first);
                last = i + 1;
            } else {
                break;
            }
        }
        while (k-- > 0) {
            if (gains.empty()) {
                break;
            }
            W += gains.top();
            gains.pop();
            for (int i = last; i < n; ++i) {
                if (pcs[i].second <= W) {
                    gains.push(pcs[i].first);
                    last = i + 1;
                } else {
                    break;
                }
            }
        }
        return W;
    }
};