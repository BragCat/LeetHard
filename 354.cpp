class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), [](auto a, auto b) -> bool {return (a.first < b.first) || (a.first == b.first && a.second < b.second);});
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        return *(max_element(f.begin(), f.end()));
    }
};