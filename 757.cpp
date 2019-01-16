class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            points.push_back({intervals[i][0], i, 1});
            points.push_back({intervals[i][1], i, -1});
        }
        sort(points.begin(), points.end(), [](auto &a, auto &b) -> bool {return (a[0] < b[0] || (a[0] == b[0] && a[2] > b[2]));});
        vector<pair<int, int>> s;
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            int num = points[i][0], index = points[i][1];
            bool isIn = points[i][2] > 0;
            if (isIn) {
                s.emplace_back(index, 0);
            } else {
                int p = s.size() - 1;
                while (s[p].first != index) {
                    --p;
                }
                int plus = max(0, 2 - s[p].second);
                ans += plus;
                if (plus > 0) {
                    for_each(s.begin(), s.end(), [](pair<int, int> &x) {++x.second;});
                    if (plus == 2) {
                        int last = s.size() - 1;
                        while (intervals[s[last].first][0] == num) {
                            --last;
                        }
                        for_each(s.begin(), s.begin() + last + 1, [](pair<int, int> &x) {++x.second;});
                    }
                }
                s.erase(s.begin() + p);
            }
        }
        return ans;
    }
};