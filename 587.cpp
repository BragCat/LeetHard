/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        int leftest = -1;
        for (int i = 0; i < points.size(); ++i) {
            if (leftest == -1 || points[leftest].x > points[i].x || (points[leftest].x == points[i].x && points[leftest].y > points[i].y)) {
                leftest = i;
            }
        }
        swap(points[0], points[leftest]);
        Point lbPoint(points[0]);
        for (auto &p : points) {
            p.x -= lbPoint.x;
            p.y -= lbPoint.y;
        }
        sort(points.begin() + 1, points.end(), [](auto &a, auto &b) -> bool {
            return (a.x * b.y - a.y * b.x) > 0 || (a.x * b.y - a.y * b.x == 0 && a.x * a.x + a.y * a.y > b.x * b.x + b.y * b.y);
        });

        vector<Point> s{points[0]};
        for (int i = 1; i < points.size(); ++i) {
            while (s.size() > 1) {
                auto b = s[s.size() - 1], a = s[s.size() - 2], c = points[i];
                Point first(b.x - a.x, b.y - a.y), second(c.x - a.x, c.y - a.y);
                if (first.x * second.y - first.y * second.x >= 0) {
                    break;
                }
                s.pop_back();
            }
            s.push_back(points[i]);
        }
        
        for (auto &p : s) {
            cout << p.x + lbPoint.x << " " << p.y + lbPoint.y << endl;
        }
        
        auto cmp = [](const Point &a, const Point &b) -> bool {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        };
        set<Point, decltype(cmp)> ans(s.begin(), s.end(), cmp);
        s.push_back(points[0]);
        for (int i = 0; i < s.size() - 1; ++i) {
            for (auto &p : points) {
                Point first(p.x - s[i].x, p.y - s[i].y), second(s[i + 1].x - s[i].x, s[i + 1].y - s[i].y);
                int cp = first.x * second.y - first.y * second.x;
                if (ans.find(p) == ans.end() && cp == 0) {
                    ans.insert(p);
                }
            }
        }
        vector<Point> results;
        for (auto &p : ans) {
            results.push_back(Point(p.x + lbPoint.x, p.y + lbPoint.y));
        }
        
        return results;
    }
};