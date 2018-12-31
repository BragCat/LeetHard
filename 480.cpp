class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<double> smaller, bigger;
        for (int i = 0; i < k; ++i) {
            add(smaller, bigger, nums[i]);
        }
        vector<double> ans{getMedian(smaller, bigger)};
        for (int i = k; i < nums.size(); ++i) {
            remove(smaller, bigger, nums[i - k]);
            add(smaller, bigger, nums[i]);
            ans.push_back(getMedian(smaller, bigger));
        }
        return ans;
    }
private:
    void add(multiset<double> &smaller, multiset<double> &bigger, int value) {
        double median = getMedian(smaller, bigger);
        if (value <= median) {
            smaller.insert(value);
        } else {
            bigger.insert(value);
        }
        adjust(smaller, bigger);
    }
    void remove(multiset<double> &smaller, multiset<double> &bigger, int value) {
        double median = getMedian(smaller, bigger);
        if (value <= median) {
            auto it = smaller.find(value);
            smaller.erase(it);
        } else {
            auto it = bigger.find(value);
            bigger.erase(it);
        }
        adjust(smaller, bigger);
    }
    double getMedian(multiset<double> &smaller, multiset<double> &bigger) {
        int n = smaller.size() + bigger.size();
        double median = 1e10;
        if (n > 0) {
            if (n % 2 == 1) {
                median = *(smaller.rbegin());
            } else {
                median = (*(smaller.rbegin()) + *(bigger.begin())) / 2.0;
            }
        }
        return median;
    }
    void adjust(multiset<double> &smaller, multiset<double> &bigger) {
        while (smaller.size() > bigger.size() + 1) {
            double value = *(smaller.rbegin());
            auto it = smaller.end();
            --it;
            smaller.erase(it);
            bigger.insert(value);
        }
        while (smaller.size() < bigger.size()) {
            double value = *(bigger.begin());
            bigger.erase(bigger.begin());
            smaller.insert(value);
        }
    }
};