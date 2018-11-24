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
    int maxPoints(vector<Point>& points) {
        if (points.size() == 0) {
            return 0; 
        }
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> count;
            int sameCnt = 1;
            for (int j = 0; j < points.size(); ++j) {
                if (i != j) {
                    int dx = points[j].x - points[i].x, dy = points[j].y - points[i].y;
                    int g = gcd(abs(dx), abs(dy));
                    if (g != 0) {
                        dx /= g, dy /= g;
                        auto it = count.find(make_pair(dx, dy));
                        if (it == count.end()) {
                            count.insert(make_pair(make_pair(dx, dy), 1));
                        } else {
                            ++it->second; 
                        }
                    } else {
                        ++sameCnt; 
                    }
                } 
            }
            for (auto item : count) {
                if (item.second + sameCnt > ans) {
                    ans = item.second + sameCnt; 
                }
            }
            if (sameCnt > ans) {
                ans = sameCnt; 
            }
        }
        return ans;
    }

private:
    int gcd(int a, int b) {
        if (a < b) {
            swap(a, b);
        }
        if (b == 0) {
            return a; 
        }
        if (a % b == 0) {
            return b; 
        } else {
            return gcd(b, a % b); 
        }
    }

    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t; 
    }
};
