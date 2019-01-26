class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> ratio2Index;
        int n = quality.size();
        for (int i = 0; i < n; ++i) {
            ratio2Index.push_back({wage[i] * 1.0 / quality[i], i});
        }
        sort(ratio2Index.begin(), ratio2Index.end(), [](auto &a, auto &b) -> bool {return a.first < b.first;});
        priority_queue<int> h;
        int tot = 0;
        for (int i = 0; i < K - 1; ++i) {
            int q = quality[ratio2Index[i].second];
            tot += q;
            h.push(q);
        }
        double ans = -1;
        for (int i = K - 1; i < n; ++i) {
            int q = quality[ratio2Index[i].second];
            double cost = ratio2Index[i].first * (tot + q);
            if (ans == -1 || ans > cost) {
                ans = cost;
            }
            if (!h.empty() && h.top() > q) {
                tot -= h.top();
                tot += q;
                h.pop();
                h.push(q);
            }
        }
        return ans;
    }
};