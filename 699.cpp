class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        int n = positions.size();
        vector<vector<int>> intervals;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int st = positions[i].first, ed = st + positions[i].second;
            int h = 0;
            for (auto &interval : intervals) {
                if (interval[0] < ed && interval[1] > st) {
                    h = max(h, interval[2]);
                }
            }
            h += positions[i].second;
            if (!ans.empty() && ans.back() > h) {
                ans.push_back(ans.back());
            } else {
                ans.push_back(h);
            }
            vector<vector<int>> newIntervals;
            for (auto &interval : intervals) {
                if (interval[0] < ed && interval[1] > st) {
                    if (interval[0] < st && interval[1] > st) {
                        newIntervals.push_back({interval[0], st, interval[2]});
                    }
                    if (interval[0] < ed && interval[1] > ed) {
                        newIntervals.push_back({ed, interval[1], interval[2]});
                    }
                } else {
                    newIntervals.push_back(interval);
                }
            }
            newIntervals.push_back({st, ed, h});
            swap(newIntervals, intervals);
        }
        return ans;
    }
};