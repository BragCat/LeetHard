class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        map<int, vector<pair<int, int>>> x2y;
        for (auto &rect : rectangles) {
            x2y[rect[0]].push_back({rect[1], 1});
            x2y[rect[0]].push_back({rect[3], -1});
            x2y[rect[2]].push_back({rect[1], -1});
            x2y[rect[2]].push_back({rect[3], 1});
        }
        
        int ans = 0, lastx = -1, lastLeny = 0;
        map<int, int> pointCnt;
        for (auto it = x2y.begin(); it != x2y.end(); ++it) { 
            ans = (ans + static_cast<long long>(lastLeny) * (it->first - lastx) % MODULO) % MODULO;
            auto &ys = it->second;
            for (auto p : ys) {
                pointCnt[p.first] += p.second;
            }
            int cnt = 0, leny = 0, sty = 0;
            for (auto p = pointCnt.begin(); p != pointCnt.end(); ++p) {
                if (cnt == 0) {
                    sty = p->first;
                }
                cnt += p->second;
                if (cnt == 0) {
                    leny = (leny + p->first - sty) % MODULO;
                }
            }
            lastx = it->first;
            lastLeny = leny;
        }
        return ans;
    }
private:
    const int MODULO = 1e9 + 7;
};