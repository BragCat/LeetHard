/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct CMP{
    bool operator ()(const Interval &a, const Interval &b) const {
        return a.start < b.start || (a.start == b.start && a.end < b.end);
    }
};
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        Interval now(val, val);
        auto lb = intervals.lower_bound(now);
        if (lb != intervals.begin()) {
            auto prev = lb;
            --prev;
            if (prev->end + 1 > now.start) {
                return;
            } else if (prev->end + 1 == now.start) {
                now.start = prev->start;
                intervals.erase(prev);
                if (lb != intervals.end() && lb->start == now.end + 1) {
                    now.end = lb->end;
                    intervals.erase(lb);
                }
                intervals.insert(now);
            } else {
                if (lb != intervals.end()) {
                    if (lb->start == now.end) {
                        return;
                    } else if (lb->start == now.end + 1) {
                        now.end = lb->end;
                        intervals.erase(lb);
                    }
                    intervals.insert(now);
                } else {
                    intervals.insert(now);
                }
            }
        } else {                    
            if (lb->start == now.end) {
                return;
            } else if (lb->start == now.end + 1) {
                now.end = lb->end;
                intervals.erase(lb);
            }
            intervals.insert(now);
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto i : intervals) {
            ans.push_back(i);
        } 
        return ans;
    }
private:
    set<Interval, CMP> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<Interval> param_2 = obj->getIntervals();
 */