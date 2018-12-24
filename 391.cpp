class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<pair<int, int>, int> pointCnt;
        int sum = 0;
        int minx, miny, maxx, maxy;
        minx = miny = MAX_INT;
        maxx = maxy = MIN_INT;
        for (auto &rect : rectangles) {
            minx = min(minx, rect[0]);
            miny = min(miny, rect[1]);
            maxx = max(maxx, rect[2]);
            maxy = max(maxy, rect[3]);
            insertPoint(pointCnt, rect[0], rect[1]);
            insertPoint(pointCnt, rect[0], rect[3]);
            insertPoint(pointCnt, rect[2], rect[1]);
            insertPoint(pointCnt, rect[2], rect[3]);
            sum += getArea(rect);
        }
        
        for (auto &p : pointCnt) {
            if (p.first == make_pair(minx, miny) || p.first == make_pair(minx, maxy) || p.first == make_pair(maxx, miny) || p.first == make_pair(maxx, maxy)) {
                if (p.second != 1) {
                    return false;
                }
            } else {
                if (p.second % 2 != 0) {
                    return false;
                }
            }
        }
        
        return sum == getArea(vector<int>{minx, miny, maxx, maxy});
    }
private:
    const int MAX_INT = ~0u >> 1;
    const int MIN_INT = -MAX_INT - 1;
    
    int getArea(vector<int> rect) const {
        return (rect[3] - rect[1]) * (rect[2] - rect[0]);
    }
    void insertPoint(map<pair<int, int>, int> &pointCnt, int x, int y) {
        ++pointCnt[{x, y}];
    }
};