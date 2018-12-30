/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int index = -1;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start < newInterval.start) {
                index = i;
            } else {
                break;
            }
        }
        intervals.insert(intervals.begin() + index + 1, newInterval);
        
        vector<Interval> ans;
        Interval now(-1, -1);
        for (auto &intv : intervals) {
            if (now.start == now.end && now.start == -1) {
                now = intv;
            } else if (now.end < intv.start) {
                ans.push_back(now);
                now = intv;
            } else {
                now.end = max(intv.end, now.end);
            }
        }
        ans.push_back(now);
        return ans;
    }
};